#pragma once

#include <any>
#include <array>
#include <memory>
#include <optional>

#include "util/business_logic_exceptions.h"
#include "util/node_util.h"
#include "util/tuple_util.h"

namespace nds {

#define NODE_SYSTEM_IMPLEMENTATION(ClassName) \
 public: \
  using func_pointer_t = std::remove_pointer_t<decltype(&ClassName::execute)>; \
  using func_result_t = nds::fun::function_result_t<func_pointer_t>; \
  using result_tuple_t = nds::fun::parse_tuple_t<func_result_t>; \
  using input_tuple_t = nds::fun::function_arguments_t<func_pointer_t>; \
  using reference_tuple_t = nds::fun::make_reference_tuple_t<input_tuple_t>; \
 \
  void run() override { \
    if constexpr (std::is_same_v<void, func_result_t>) { \
      std::apply([this]<typename... TArguments>(TArguments&&... args) { \
        this->execute(std::forward<TArguments>(args)...); }, get_node_inputs<reference_tuple_t>(inputs_)); \
    } else if constexpr (nds::fun::is_instantiation_of_v<std::tuple, func_result_t>) { \
      result_ = std::move(std::apply([this]<typename... TArguments>(TArguments&&... args) { \
        return this->execute(std::forward<TArguments>(args)...); }, get_node_inputs<reference_tuple_t>(inputs_))); \
    } else { \
      result_ = std::move(std::make_tuple(std::apply([this]<typename... TArguments>(TArguments&&... args) { \
        return this->execute(std::forward<TArguments>(args)...); }, get_node_inputs<reference_tuple_t>(inputs_)))); \
    } \
  } \
 \
  bool connect_input(std::shared_ptr<Node> src_node, std::size_t src_index, std::size_t dest_index, \
      std::shared_ptr<Node>& previous_node) override { \
    previous_node = inputs_[dest_index].node; \
    if (nds::fun::get_tuple_value_type_id<input_tuple_t>(dest_index) != src_node->get_result_elem_type_id(src_index)) { \
      return false; \
    } \
    invalidate(); \
    inputs_[dest_index].node = src_node; \
    inputs_[dest_index].index = src_index; \
    return true; \
  } \
 \
  void invalidate() override { \
    result_ = {}; \
  } \
 \
  void* get_result_elem(std::size_t index) override { \
    if (!result_.has_value()) { \
      run(); \
    } \
    return nds::fun::get_tuple_value(result_.value(), index); \
  } \
 \
  size_t get_result_elem_type_id(std::size_t index) override { \
    return nds::fun::get_tuple_value_type_id<result_tuple_t>(index); \
  } \
 \
 private:\
  std::array<NodeResultPointer, std::tuple_size_v<reference_tuple_t>> inputs_; \
  std::optional<result_tuple_t> result_;

/// @brief Base class for program nodes.
/// Actions to create new node class:
/// 1. Inherent new class from `nds::Node`.
/// 2. At the end of class append macros `NODE_SYSTEM_IMPLEMENTATION` with class signature as parameter.
/// 3. Write function called `execution`:
///   - arguments will be passed from other nodes;
///   - result can be passed to other nodes:
///     - `std::tuple<TArgs...>` if each element of TArgs must be separate output;
///     - `void` or `std::tuple<>` if there is no output;
///     - some type `T` or `std::tuple<T>` if there is single output;
/// `execution` function will be called to run node or to get result of node.
///
/// @note Child class can store state between calls in its fields and use them as `execute` is member function.
class Node {
 public:
  virtual ~Node() = default;

  /// @brief Starts execution of node.
  /// All inputs of current node must be connected with outputs of other nodes.
  /// If an input of this node need a result of another node's work, recursively runs other node's execution.
  virtual void run() = 0;

  /// @brief Connects to input of this node output of other node.
  /// @param src_node node whose result will be connected.
  /// @param src_index index of output in src_node.
  /// @param dest_index index of input in this node.
  /// @param previous_node variable of pointer to node which will be set to previous node pointer.
  /// @return true if types of input and output are same and indexes are correct, else false.
  virtual bool connect_input(std::shared_ptr<Node> src_node, std::size_t src_index,
    std::size_t dest_index, std::shared_ptr<Node>& previous_node) = 0;

  /// @brief Deletes result of this node's work.
  virtual void invalidate() = 0;

  /// @brief Gets specific result of work of this node by index.
  virtual void* get_result_elem(std::size_t index) = 0;

  /// @brief Gets type id of specific result of work of this node by index.
  virtual size_t get_result_elem_type_id(std::size_t index) = 0;

 protected:
  struct NodeResultPointer {
    std::shared_ptr<Node> node = nullptr;
    std::size_t index = 0;
  };

  /// @warning Function with side effects for node execution.
  template<typename Tuple>
  Tuple get_node_inputs(const std::array<NodeResultPointer, std::tuple_size_v<Tuple>>& previous_results) {
    return initialize_tuple_impl<Tuple>(previous_results, std::make_index_sequence<std::tuple_size_v<Tuple>>());
  }

  /// @warning Function with side effects for node execution.
  template <typename Tuple, std::size_t... Ind>
  Tuple initialize_tuple_impl(
      const std::array<NodeResultPointer, std::tuple_size_v<Tuple>>& previous_results,
      std::index_sequence<Ind...>) {
    if ((... || (previous_results[Ind].node == nullptr))) {
      throw exc::no_source_error();
    }
    return std::make_tuple(
      std::ref(*reinterpret_cast<typename std::tuple_element_t<Ind, Tuple>::type*>(
        previous_results[Ind].node->get_result_elem(previous_results[Ind].index)))...);
  }
};

} // nds
