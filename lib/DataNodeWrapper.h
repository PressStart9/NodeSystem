#pragma once

#include <optional>

#include "Node.h"

namespace nds {

/// @brief Default class for data nodes handling.
/// To introduce new node, you should pass callable object to constructor of this class.
/// For callable function would be true next statements:
///   - arguments will be passed from other nodes;
///   - result can be passed to other nodes:
///     - `std::tuple<TArgs...>` if each element of TArgs must be separate output;
///     - `void` or `std::tuple<>` if there is no output;
///     - some type `T` or `std::tuple<T>` if there is single output;
///   - function will be called to run node or to get result of node;
template<typename DataFunctor>
class DataNodeWrapper : public DataNode {
 public:
  using func_pointer_t = std::remove_pointer_t<decltype(&DataFunctor::operator())>;
  using func_result_t = fun::function_result_t<func_pointer_t>;
  using result_tuple_t = fun::parse_tuple_t<func_result_t>;
  using input_tuple_t = fun::function_arguments_t<func_pointer_t>;
  using reference_tuple_t = fun::make_reference_tuple_t<input_tuple_t>;

  explicit DataNodeWrapper(const DataFunctor& functor) : functor_(functor) {}
  explicit DataNodeWrapper(DataFunctor&& functor) : functor_(std::move(functor)) {}

  /// @copydoc DataNode::act
  void act() override {
    if constexpr (std::is_same_v<void, func_result_t>) {
      std::apply(functor_, get_node_inputs<reference_tuple_t>(inputs_));
    } else if constexpr (nds::fun::is_instantiation_of_v<std::tuple, func_result_t>) {
      result_ = std::move(std::apply(functor_, get_node_inputs<reference_tuple_t>(inputs_)));
    } else {
      result_ = std::move(std::make_tuple(std::apply(functor_, get_node_inputs<reference_tuple_t>(inputs_))));
    }
  }

  // TODO: add overload function documentation
  bool connect_input(std::shared_ptr<DataNode> src_node, std::size_t src_index, std::size_t dest_index) override {
    std::shared_ptr<DataNode> temp;
    return connect_input(std::move(src_node), src_index, dest_index, temp);
  }

  bool connect_input(std::shared_ptr<DataNode> src_node, std::size_t src_index, std::size_t dest_index,
                     std::shared_ptr<DataNode>& previous_node) override {
    previous_node = inputs_[dest_index].node;
    if (fun::get_tuple_value_type_id<input_tuple_t>(dest_index) != src_node->get_result_elem_type_id(src_index)) {
      return false;
    }
    invalidate();
    inputs_[dest_index].node = src_node;
    inputs_[dest_index].index = src_index;
    return true;
  }

  /// @copydoc DataNode::invalidate
  void invalidate() override {
    result_ = {};
  }

  /// @copydoc DataNode::get_result_elem
  void* get_result_elem(std::size_t index) override {
    if (!result_.has_value()) {
      act();
    }
    return fun::get_tuple_value(result_.value(), index);
  }

  /// @copydoc DataNode::get_result_elem_type_id
  size_t get_result_elem_type_id(std::size_t index) override {
    return fun::get_tuple_value_type_id<result_tuple_t>(index);
  }

 protected:
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

 private:
  std::array<NodeResultPointer, std::tuple_size_v<reference_tuple_t>> inputs_;
  std::optional<result_tuple_t> result_;

  DataFunctor functor_;
};

} // nds