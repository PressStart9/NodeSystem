#pragma once

#include "examples/data_nodes/CounterNode.h"
#include "abstract/ControlNodeWrapper.h"
#include "abstract/DataNodeWrapper.h"

namespace nds::ex {

class ForNode {
 public:
  static constexpr size_t size = 1;

  BranchInfo operator()(DataNodeWrapper<CounterNode>* node) const {
    return {0, node->get_functor().done(), true};
  }
};

} // nds::ex
