#pragma once

#include <iostream>

namespace nds::ex {

template<typename... Args>
class PrintNode {
 public:
  void operator()(const Args&... args) {
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
};

} // nds::ex
