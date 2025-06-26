#pragma once

namespace nds::ex {

template<typename T>
class SumNode {
 public:
  T operator()(const T& a, const T& b) {
    return a + b;
  }
};

} // nds::ex
