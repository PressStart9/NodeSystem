#pragma once

#include "abstract/DataNodeWrapper.h"
#include "examples/data_nodes/GetNode.h"

namespace nds::ex {

template<typename T>
class BranchNode {
 public:
  static constexpr size_t size = 2;

  size_t operator()(DataNodeWrapper<GetNode<T>>* node) const {
    return node->get_functor().get_value() ? 0 : 1;
  }
};

} // nds::ex
