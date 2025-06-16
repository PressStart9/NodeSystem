#include "util/util.h"


RESET_CALL_COUNTER_EACH_TEST(ControlNodeTests)

using namespace nds;

TEST_F(ControlNodeTests, DefaultTest) {
  auto a = VAR(CallCounter, CallCounter{});

  auto d = CHECK(CallCounter());
  d.connect_input(&a, 0, 0);
  d.act();
}
