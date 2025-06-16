#pragma once

#include <gtest/gtest.h>

#include <tuple>
#include <utility>

namespace nds::ex {

template<typename... Args>
class CheckNode {
 public:
  explicit CheckNode(Args&&... expected_args)
    : expected_args_(std::move(expected_args)...) {}

  void operator()(const Args&... actual_args) {
    checkArguments(std::index_sequence_for<Args...>{}, actual_args...);
  }

 private:
  template<std::size_t... I>
  void checkArguments(std::index_sequence<I...>, const Args&... actual_args) {
    int _[] = {
      (assert_one(std::get<I>(expected_args_), actual_args), 0)...
    };
    (void)_;
  }

  template<typename T, typename U>
  void assert_one(const T& expected, const U& actual) {
    ASSERT_EQ(expected, actual);
  }

  std::tuple<Args...> expected_args_;
};

} // nds::ex
