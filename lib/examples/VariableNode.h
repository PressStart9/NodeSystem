#pragma once

namespace nds::ex {

template<typename T>
class VariableNode {
 public:
  explicit VariableNode(const T& value) : var_(value) {}
  explicit VariableNode(T&& value) : var_(std::move(value)) {}

  T operator()() {
    return {var_};
  }

 private:
  T var_;
};

} // nds::ex
