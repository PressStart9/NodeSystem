#pragma once

#include <Node.h>

template<typename T>
class VariableNode : public nds::Node {
 public:
  explicit VariableNode(const T& value) : var_(value) {}
  explicit VariableNode(T&& value) : var_(std::move(value)) {}

  T execute() {
    return {var_};
  }

 private:
  T var_;

  VIRTUAL_FUNCTION_WRAPPER(VariableNode<T>);
};
