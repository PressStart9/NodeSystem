#pragma once

#include <abstract/DataNodeWrapper.h>

namespace nds::ex {

template<typename T>
class BranchNode {
 public:
  size_t operator()(DataNodeWrapper<VariableNode<T>>* node) const {
    return node->get_functor().get_value() ? 0 : 1;
  }
};

} // nds::ex
