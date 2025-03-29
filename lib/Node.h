#pragma once

#include <any>

#include "tuple_util.h"

namespace nds {

#define VIRTUAL_FUNCTION_WRAPPER

class Node {
 public:
  virtual ~Node() = default;

  virtual void run() = 0;

  virtual std::any get_result_elem(std::size_t index) = 0;

  struct NodeResultPointer {
    Node* node;
    std::size_t index;
  };

 protected:
  template<typename Tuple>
  Tuple get_node_inputs(const std::array<NodeResultPointer, std::tuple_size_v<Tuple>>& previous_results) {
    Tuple inputs;
    std::size_t index = 0;

    std::apply([&]<typename... Args>(Args&... elems) {
        ((elems = std::any_cast<Args>(previous_results[index].node->get_result_elem(previous_results[index++].index))), ...);
    }, inputs);

    return inputs;
  }
};

} // nds
