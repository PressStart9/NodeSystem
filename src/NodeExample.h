#pragma once

#include <array>

#include "Node.h"

class NodeExample : public nds::Node {
 public:
  using result_tuple = std::tuple<bool, int, std::string>;
  using input_tuple = std::tuple<std::string, bool, int>;

  void run() override {
    result = std::apply(execute, get_node_inputs<input_tuple>(inputs));
  }

  std::any get_result_elem(std::size_t index) override {
    return fun::get_tuple_value(result, index);
  }

  std::array<NodeResultPointer, 3> inputs;
  result_tuple result;

  static result_tuple execute(const std::string& a, bool b, int c) {
    std::cout << a << ' ' << b << ' ' << c << '\n';
    return {};
  }
};