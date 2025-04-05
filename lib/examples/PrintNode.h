#pragma once

#include "Node.h"

namespace nds::ex {

template<typename... Args>
class PrintNode : public nds::Node {
 public:
  void execute(const Args&... args) {
    execute_impl(args...);
  }

 private:
  static void execute_impl() {
  	std::cout << '\n';
  }

  template <typename Head, typename... Tail>
  static void execute_impl(const Head& first, const Tail&... args) {
    std::cout << first;
    if (sizeof...(args) > 0) {
      std::cout << " ";
    }
    execute_impl(args...);
  }

  NODE_SYSTEM_IMPLEMENTATION(PrintNode<Args...>);
};

} // nds::ex