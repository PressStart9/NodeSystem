#pragma once

#include <Node.h>

template<typename T>
class VariableNode : public nds::Node {
 public:
  using result_tuple = std::tuple<T>;
  using input_tuple = std::tuple<>;

  explicit VariableNode(const T& value) : var_(value) {
  }

  result_tuple execute() {
    return {var_};
  }

 private:
  T var_;

  VIRTUAL_FUNCTION_WRAPPER;
};
