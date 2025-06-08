#pragma once

#include "abstract/DataNodeWrapper.h"
#include "examples/data_nodes/ConstantNode.h"

namespace nds::ex {

template<typename T>
class BranchNode {
 public:
  size_t operator()(DataNodeWrapper<ConstantNode<T>>* node) const {
    return node->get_functor().get_value() ? 0 : 1;
  }
};

} // nds::ex
