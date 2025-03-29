#pragma once

#include <any>
#include <array>
#include <optional>

#include "tuple_util.h"

namespace nds {

#define VIRTUAL_FUNCTION_WRAPPER \
 private: \
  template <typename Tuple> \
  struct make_reference_tuple; \
 \
  template <typename... TArguments> \
  struct make_reference_tuple<std::tuple<TArguments...>> { \
    using type = std::tuple<std::reference_wrapper<TArguments>...>; \
  }; \
 \
  using reference_tuple = typename make_reference_tuple<input_tuple>::type; \
 \
 public: \
  void run() override { \
    result_ = std::move(std::apply([this]<typename... TArgumentss>(TArgumentss&&... args) { \
      return this->execute(std::forward<TArgumentss>(args)...); }, get_node_inputs<reference_tuple>(inputs_))); \
  } \
 \
  void connect_input(Node& src_node, std::size_t src_index, std::size_t dest_index) override { \
    invalidate(); \
    inputs_[dest_index] = { &src_node, src_index }; \
  } \
 \
  void invalidate() override { \
    result_ = {}; \
  } \
 \
 private:\
  std::any get_result_elem(std::size_t index) override { \
    if (!result_.has_value()) { \
      run(); \
    } \
    return fun::get_tuple_value(result_.value(), index); \
  } \
 \
  std::array<NodeResultPointer, std::tuple_size_v<reference_tuple>> inputs_; \
  std::optional<result_tuple> result_;

class Node {
 public:
  virtual ~Node() = default;

  virtual void run() = 0;

  virtual void connect_input(Node& src_node, std::size_t src_index, std::size_t dest_index) = 0;

  virtual void invalidate() = 0;

 protected:
  virtual std::any get_result_elem(std::size_t index) = 0;

  struct NodeResultPointer {
    Node* node = nullptr;
    std::size_t index = 0;
  };

  template<typename Tuple>
  Tuple get_node_inputs(const std::array<NodeResultPointer, std::tuple_size_v<Tuple>>& previous_results) {
    return initialize_tuple_impl<Tuple>(previous_results, std::make_index_sequence<std::tuple_size_v<Tuple>>());
  }

  template <typename Tuple, std::size_t... Ind>
  Tuple initialize_tuple_impl(
      const std::array<NodeResultPointer, std::tuple_size_v<Tuple>>& previous_results,
      std::index_sequence<Ind...>) {
    return std::make_tuple(
      previous_results[Ind].node == nullptr ?
      throw std::runtime_error("All inputs of node must be connected.") :
      std::any_cast<std::tuple_element_t<Ind, Tuple>>(
        previous_results[Ind].node->get_result_elem(previous_results[Ind].index))...);
  }
};

} // nds
