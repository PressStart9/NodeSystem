#include <gtest/gtest.h>

#include "abstract/DataNodeWrapper.h"

#include "examples/data_nodes/VariableNode.h"

#include "util/util.h"

CALL_COUNTER_STATIC_INIT(DataNodeTests)

std::string variable_function() { return "string"; }

TEST_F(DataNodeTests, DefaultTest) {
  auto a = VAR(CallCounter, CallCounter{});
  auto f = []() { return 2.2f; };
  auto b = new nds::DataNodeWrapper(f);
  auto c = new nds::DataNodeWrapper<decltype(&variable_function)>(variable_function);

  auto d = CHECK(CallCounter(), 2.2f, std::string("string"));
  d->connect_input(a, 0, 0);
  d->connect_input(b, 1, 1);
  d->connect_input(c, 2, 2);

  ASSERT_FALSE(d->connect_input(a, 0, 1));

  d->act();

  ASSERT_EQ(1, CallCounter::copy_construct_count);
  ASSERT_EQ(0, CallCounter::copy_assign_count);

  ASSERT_EQ(0, CallCounter::delete_count);
  ASSERT_EQ(0, CallCounter::delete_array_count);

  std::cout << CallCounter{} << '\n';
}
