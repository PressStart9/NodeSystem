#pragma once

#include <cstdint>

namespace nds::ex {

class CounterNode {
 public:
  CounterNode(size_t end_index) : end_(end_index), current_(start_) {}
  CounterNode(size_t start_index, size_t end_index) : start_(start_index), end_(end_index), current_(start_) {}
  CounterNode(size_t start_index, size_t end_index, size_t step) : start_(start_index), end_(end_index), step_(step), current_(start_) {}

  size_t operator()() {
    return ++current_;
  }

  bool done() {
    return current_ >= end_;
  }

 private:
  size_t start_ = 0;
  size_t end_;
  size_t step_ = 1;

  size_t current_;
};

} // nds::ex
