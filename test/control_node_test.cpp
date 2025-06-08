#include "util/util.h"


RESET_CALL_COUNTER_EACH_TEST(ControlNodeTests)

using namespace nds;

TEST_F(ControlNodeTests, DefaultTest) {
  auto a = CONST(CallCounter, CallCounter{});
}
