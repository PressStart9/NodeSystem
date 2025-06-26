#pragma once

namespace nds::ex {

template<typename T>
class CounterNode {
 public:
  explicit CounterNode(T end_index) : end_(end_index), current_(0) {}
  CounterNode(T start_index, T end_index) : end_(end_index), current_(start_index) {}
  CounterNode(T start_index, T end_index, T step) : end_(end_index), step_(step), current_(start_index) {}

  T operator()() {
    return current_++;
  }

  bool done() {
    return current_ >= end_;
  }

 private:
  T end_;
  T step_ = 1;

  T current_;
};

} // nds::ex
