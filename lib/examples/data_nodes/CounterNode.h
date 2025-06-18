#pragma once

#include <cstdint>

namespace nds::ex {

class CounterNode {
 public:
  CounterNode(size_t end_index) : end_(end_index), current_(0) {}
  CounterNode(size_t start_index, size_t end_index) : end_(end_index), current_(start_index) {}
  CounterNode(size_t start_index, size_t end_index, size_t step) : end_(end_index), step_(step), current_(start_index) {}

  size_t operator()() {
    if (!is_init) {
      is_init = true;
      return current_;
    }
    return ++current_;
  }

  bool done() {
    return current_ >= end_;
  }

 private:
  size_t end_;
  size_t step_ = 1;

  size_t current_;
  bool is_init = false;
};

} // nds::ex
