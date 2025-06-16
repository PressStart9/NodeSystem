#pragma once

namespace nds::ex {

template<typename T>
class VariableNode {
 public:
  explicit VariableNode(const T& default_value) : var_(default_value) {}
  explicit VariableNode(T&& default_value) : var_(std::move(default_value)) {}

  T& operator()() {
    return var_;
  }

  void set_value(const T& value) { var_ = value; }
  void set_value(T&& value) { var_ = value; }

  const T& get_value() const { return var_; }

 private:
  T var_;
};

} // nds::ex
