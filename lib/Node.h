#pragma once

#include <any>
#include <array>
#include <optional>

#include "tuple_util.h"

namespace nds {

#define VIRTUAL_FUNCTION_WRAPPER \
 public: \
  void run() override { \
    result_ = std::apply([this]<typename... TArgumentss>(TArgumentss&&... args) { \
      return this->execute(std::forward<TArgumentss>(args)...); }, get_node_inputs<input_tuple>(inputs_)); \
  } \
  void connect_input(Node& src_node, std::size_t src_index, std::size_t dest_index) override { \
    inputs_[dest_index] = { &src_node, src_index }; \
  } \
 private:\
  std::any get_result_elem(std::size_t index) override { \
    if (!result_.has_value()) { \
      run(); \
    } \
    return fun::get_tuple_value(result_.value(), index); \
  } \
 \
  std::array<NodeResultPointer, std::tuple_size_v<input_tuple>> inputs_; \
  std::optional<result_tuple> result_;

class Node {
 public:
  virtual ~Node() = default;

  virtual void run() = 0;

  virtual void connect_input(Node& src_node, std::size_t src_index, std::size_t dest_index) = 0;

 protected:
  virtual std::any get_result_elem(std::size_t index) = 0;

  struct NodeResultPointer {
    Node* node;
    std::size_t index;
  };

  template<typename Tuple>
  Tuple get_node_inputs(const std::array<NodeResultPointer, std::tuple_size_v<Tuple>>& previous_results) {
    Tuple inputs;
    std::size_t index = 0;

    std::apply([&]<typename... Args>(Args&... elems) {
        ((elems = std::any_cast<std::decay_t<Args>>(
          previous_results[index].node->get_result_elem(previous_results[index++].index))
          ), ...);
    }, inputs);

    return inputs;
  }
};

} // nds
