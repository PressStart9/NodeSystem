#pragma once

#include "examples/data_nodes/CounterNode.h"
#include "abstract/ControlNodeWrapper.h"
#include "abstract/DataNodeWrapper.h"

namespace nds::ex {

template<typename T>
class ForNode {
 public:
  static constexpr size_t size = 1;

  BranchInfo operator()(DataNodeWrapper<CounterNode<T>>* node) const {
    return {0, node->get_functor().done(), true};
  }
};

} // nds::ex
