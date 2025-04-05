#pragma once

#include <Node.h>

namespace nds::ex {
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

  NODE_SYSTEM_IMPLEMENTATION(VariableNode<T>);
};
} // nds::ex
