#pragma once

#include <abstract/DataNodeWrapper.h>

namespace nds::ex {

template<typename T>
class LinearNode {
 public:
  size_t operator()(DataNodeWrapper<T>*) const {
    return 0;
  }
};

} // nds::ex
