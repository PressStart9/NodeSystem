#pragma once

#include <optional>

#include "DataNode.h"
#include "util/business_logic_exceptions.h"
#include "util/node_util.h"
#include "util/tuple_util.h"

namespace nds {

/// @brief Default class for data nodes handling.
/// To introduce new node, you should pass functor or lambda to constructor of this class.
/// @tparam DataFunctor functor that executes as node runs.
///   - arguments will be passed from other nodes;
///   - result can be passed to other nodes:
///     - `std::tuple<TArgs...>` if each element of TArgs must be separate output;
///     - `void` or `std::tuple<>` if there is no output;
///     - some type `T` or `std::tuple<T>` if there is single output;
///   - function will be called to run node or to get result of node;
template<typename DataFunctor>
class DataNodeWrapper : public DataNode {
 public:
  using decay_data_functor_t = std::decay_t<DataFunctor>;
  using func_t = fun::callable_func_t<decay_data_functor_t>;
  using func_result_t = fun::function_result_t<func_t>;
  using result_tuple_t = fun::parse_tuple_t<func_result_t>;
  using result_reference_tuple_t = fun::make_reference_tuple_t<result_tuple_t>;
  using input_tuple_t = fun::function_arguments_t<func_t>;

  explicit DataNodeWrapper(const DataFunctor& functor) : functor_(functor) {}
  explicit DataNodeWrapper(DataFunctor&& functor) : functor_(std::move(functor)) {}

  DataNodeWrapper(const DataNodeWrapper& wrapper) : functor_(wrapper.functor_) {}
  DataNodeWrapper(DataNodeWrapper&& wrapper) noexcept : functor_(std::move(wrapper.functor_)) {}

  DataNodeWrapper& operator=(const DataNodeWrapper& wrapper) = delete;
  DataNodeWrapper& operator=(DataNodeWrapper&& wrapper) noexcept = delete;

  /// @copydoc DataNode::act
  void act() override {
    if constexpr (std::is_same_v<void, func_result_t>) {
      std::apply(functor_, get_node_inputs());
    } else if constexpr (nds::fun::is_instantiation_of_v<std::tuple, func_result_t>) {
      result_ = std::apply(functor_, get_node_inputs());
    } else {
      result_ = std::make_tuple<std::tuple_element_t<0, result_reference_tuple_t>>(std::apply(functor_, get_node_inputs()));
    }
  }

  /// @copydoc DataNode::connect_input
  bool connect_input(DataNode* src_node, std::size_t src_index, std::size_t dest_index) override {
    ElementTypeInfo from_info = src_node->get_result_elem_type_info(src_index);
    ElementTypeInfo to_info = fun::get_tuple_value_type_info<input_tuple_t>(dest_index);
    if (dest_index >= inputs_.size() ||
        src_index >= src_node->outputs_size() ||
        !from_info.implies(to_info)) {
      return false;
    }
    inputs_[dest_index].node = src_node;
    inputs_[dest_index].index = src_index;
    return true;
  }

  size_t outputs_size() const override {
    return std::tuple_size_v<result_tuple_t>;
  }

  decay_data_functor_t& get_functor() {
    return functor_;
  }

  const decay_data_functor_t& get_functor() const {
    return functor_;
  }

  /// @copydoc DataNode::is_done
  bool is_done() override {
    return result_.has_value();
  }

  /// @copydoc DataNode::invalidate
  void invalidate() override {
    result_ = {};
  }

  /// @copydoc DataNode::get_result_elem
  /// @warning If node stores `std::reference_wrapper`, return pointer to original object. Invalidation of its node without invalidation this node is undefined behaviour.
  void* get_result_elem(std::size_t index) override {
    if (!result_.has_value()) {
      act();
    }
    return fun::get_tuple_value(result_.value(), index);
  }

  /// @copydoc DataNode::get_result_elem_type_id
  ElementTypeInfo get_result_elem_type_info(std::size_t index) override {
    return fun::get_tuple_value_type_info<result_tuple_t>(index);
  }

 protected:
  struct NodeResultPointer {
    DataNode* node = nullptr;
    std::size_t index = 0;
  };

  /// @warning Function with side effects for node execution.
  auto get_node_inputs() {
    return initialize_tuple_impl(std::make_index_sequence<std::tuple_size_v<input_tuple_t>>());
  }

  /// @warning Function with side effects for node execution.
  template <std::size_t... Ind>
  auto initialize_tuple_impl(std::index_sequence<Ind...>) {
    if ((... || (inputs_[Ind].node == nullptr))) {
      throw exc::no_source_error();
    }
    // if constexpr (sizeof...(Ind) > 0) {
    //   auto test1 = inputs_[0].node->get_result_elem(inputs_[0].index);
    //   auto test = reinterpret_cast<fun::ref_or_left_t<std::tuple_element_t<0, input_reference_tuple_t>>*>(test1);
    //   auto test2 = *test;
    // }
    return std::make_tuple(
      std::ref(*reinterpret_cast<std::remove_reference_t<std::tuple_element_t<Ind, input_tuple_t>>*>(
        inputs_[Ind].node->get_result_elem(inputs_[Ind].index)))...);
  }

  std::array<NodeResultPointer, std::tuple_size_v<input_tuple_t>> inputs_;
  std::optional<result_reference_tuple_t> result_;

  decay_data_functor_t functor_;
};

} // nds
