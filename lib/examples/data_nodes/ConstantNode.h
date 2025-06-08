#pragma once

namespace nds::ex {

template<typename T>
class ConstantNode {
 public:
  explicit ConstantNode(const T& value) : var_(value) {}
  explicit ConstantNode(T&& value) : var_(std::move(value)) {}

  T operator()() {
    return {var_};
  }

  void set_value(const T& value) { var_ = value; }
  void set_value(T&& value) { var_ = value; }

  const T& get_value() const { return var_; }

 private:
  T var_;
};

} // nds::ex
