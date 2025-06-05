#pragma once

#include "examples/data_nodes/CounterNode.h"
#include "abstract/ControlNodeWrapper.h"
#include "abstract/DataNodeWrapper.h"

namespace nds::ex {

class ForNode {
 public:
  BranchInfo operator()(DataNodeWrapper<CounterNode>* node) const {
    BranchInfo result = {0, node->get_functor().done(), true};
    node->get_functor()();
    return result;
  }
};

} // nds::ex
