#pragma once

#include <abstract/DataNodeWrapper.h>

namespace nds::ex {

class LinearNode {
 public:
  static constexpr size_t size = 1;

  size_t operator()() const {
    return 0;
  }
};

} // nds::ex
