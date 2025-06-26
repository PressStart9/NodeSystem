#include "util/util.h"

RESET_CALL_COUNTER_EACH_TEST(ControlNodeTests)

using namespace nds;

TEST_F(ControlNodeTests, DefaultTest) {
  auto var = DataNodeWrapper(ex::VariableNode<size_t>(0));
  auto seq = ControlNodeWrapper(ex::SequentialNode<2>(), ex::EmptyNode());
  auto forn = ControlNodeWrapper(ex::ForNode(), ex::CounterNode<size_t>(10));
  auto sum = LINEAR(ex::SumNode<size_t>());
  auto set = LINEAR(ex::SetNode<size_t>());
  auto check = LINEAR(ex::CheckNode(size_t{(0 + 9) * 10 / 2}));

  sum.get_data_node()->connect_input(&var, 0, 0);
  sum.get_data_node()->connect_input(forn.get_data_node(), 0, 1);

  set.get_data_node()->connect_input(&var, 0, 0);
  set.get_data_node()->connect_input(sum.get_data_node(), 0, 1);

  check.get_data_node()->connect_input(&var, 0, 0);

  seq.connect_next(&forn, 0);
  seq.connect_next(&check, 1);

  forn.connect_next(&sum, 0);
  sum.connect_next(&set, 0);

  seq.start();
}
