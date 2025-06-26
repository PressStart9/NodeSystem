#pragma once

namespace nds::ex {

template<typename T>
class SetNode {
 public:
  T& operator()(T& a, const T& b) {
    a = b;
    return a;
  }
};

} // nds::ex
