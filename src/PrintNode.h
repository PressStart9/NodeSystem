#pragma once

#include "Node.h"

template<typename... Args>
class PrintNode : public nds::Node {
 public:
  using result_tuple = std::tuple<>;
  using input_tuple = std::tuple<Args...>;

  result_tuple execute(const Args&... args) {
    execute_impl(args...);
    return {};
  }

 private:
  void execute_impl() {
  	std::cout << '\n';
  }

  template <typename Head, typename... Tail>
  void execute_impl(const Head& first, const Tail&... args) {
    std::cout << first;
    if (sizeof...(args) > 0) {
      std::cout << " ";
    }
    execute_impl(args...);
  }

  VIRTUAL_FUNCTION_WRAPPER;
};