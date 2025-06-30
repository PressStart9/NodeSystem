#pragma once

#include <functional>
#include <optional>

namespace nds::ex {

template<typename T>
class GetNode {
 public:
  void operator()(const T& a) {
    ref_ = &a;
  }

  const T& get_value() const {
    return *ref_;
  }

  const T* ref_ = nullptr;
};

} // nds::ex
