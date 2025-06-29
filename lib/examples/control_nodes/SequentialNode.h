#pragma once

#include "abstract/ControlNodeWrapper.h"

namespace nds::ex {

template<size_t BranchCount>
class SequentialNode {
 public:
  static constexpr size_t size = BranchCount;

  BranchInfo operator()() {
    BranchInfo info = {current_, current_ >= size, true};
    ++current_;
    return info;
  }

  size_t current_ = 0;
};

} // nds::ex
