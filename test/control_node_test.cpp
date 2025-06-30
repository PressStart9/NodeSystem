#include "util/util.h"

RESET_CALL_COUNTER_EACH_TEST(ControlNodeTests)

using namespace nds;

TEST_F(ControlNodeTests, DefaultTest) {
  auto var = DataNodeWrapper(ex::VariableNode<size_t>(0));
  auto seq = ControlNodeWrapper(ex::SequentialNode<2>(), ex::EmptyNode());
  auto forn = ControlNodeWrapper(ex::ForNode<size_t>(), ex::CounterNode<size_t>(10));
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

TEST_F(ControlNodeTests, SuccessfulDataConnectTest) {
  auto a = LINEAR(ex::ConstantNode<int>(0));
  auto b = LINEAR(ex::CheckNode<int>(0));

  ASSERT_TRUE(b.get_data_node()->connect_input(a.get_data_node(), 0, 0));
}

TEST_F(ControlNodeTests, SuccessfulConnectTest) {
  auto a = LINEAR(ex::EmptyNode());
  auto b = LINEAR(ex::EmptyNode());

  ASSERT_TRUE(a.connect_next(&b, 0));
}

TEST_F(ControlNodeTests, SourceOutOfRangeConnectTest) {
  auto a = LINEAR(ex::EmptyNode());
  auto b = LINEAR(ex::EmptyNode());

  ASSERT_FALSE(a.connect_next(&b, 1));
}

size_t five_linear_function(void*, std::integral_constant<int, 5>) {
  return 4;
}

TEST_F(ControlNodeTests, FunctionSizeTest) {
  auto a = ControlNodeWrapper(five_linear_function, ex::EmptyNode());

  ASSERT_EQ(5, decltype(a)::branches_count);
}

TEST_F(ControlNodeTests, LambdaSizeTest) {
  auto a = ControlNodeWrapper([](void*, std::integral_constant<size_t, 6>){ return 5; }, ex::EmptyNode());

  ASSERT_EQ(6, decltype(a)::branches_count);
}

TEST_F(ControlNodeTests, NoPointerSizeTest) {
  auto a = ControlNodeWrapper([](std::integral_constant<size_t, 10>){ return 5; }, ex::EmptyNode());

  ASSERT_EQ(10, decltype(a)::branches_count);
}

TEST_F(ControlNodeTests, SequencePassTest) {
  constexpr int chain_size = 10;

  auto a = std::shared_ptr<ControlNode>(new LINEAR(ex::ConstantNode(CallCounter{})));

  auto lam = [](const CallCounter& cc) -> const CallCounter& { return cc; };

  auto chain = std::array<std::shared_ptr<ControlNode>, chain_size>({a});
  for (int i = 1; i < chain_size; ++i) {
    chain[i] = std::shared_ptr<ControlNode>(new LINEAR(lam));
    chain[i]->get_data_node()->connect_input(chain[i - 1]->get_data_node(), 0, 0);
    chain[i - 1]->connect_next(chain[i].get(), 0);
  }

  auto b = std::shared_ptr<ControlNode>(new LINEAR(CHECK(CallCounter{})));
  b->get_data_node()->connect_input(chain.back()->get_data_node(), 0, 0);
  chain.back()->connect_next(b.get(), 0);

  a->start();

  ASSERT_EQ(0, CallCounter::copy_construct_count);
  ASSERT_EQ(0, CallCounter::copy_assign_count);
  ASSERT_EQ(0, CallCounter::move_assign_count);

  ASSERT_EQ(0, CallCounter::new_count);
  ASSERT_EQ(0, CallCounter::new_array_count);
  ASSERT_EQ(0, CallCounter::delete_count);
  ASSERT_EQ(0, CallCounter::delete_array_count);

  ASSERT_EQ(CallCounter::move_construct_count, CallCounter::destruct_count);

  std::cout << CallCounter();
}

TEST_F(ControlNodeTests, ForLoopTest) {
  auto loop = ControlNodeWrapper(ex::ForNode<size_t>(), DataNodeWrapper(ex::CounterNode<size_t>(10)));
  size_t counter = 0;
  auto b = LINEAR([&counter](size_t i){ ASSERT_EQ(counter++, i); });

  b.get_data_node()->connect_input(loop.get_data_node(), 0, 0);
  loop.connect_next(&b, 0);

  loop.start();
  ASSERT_EQ(10, counter);
}

TEST_F(ControlNodeTests, BranchTest) {
  auto loop = ControlNodeWrapper(ex::ForNode<size_t>(), DataNodeWrapper(ex::CounterNode<size_t>(2)));
  auto branch = ControlNodeWrapper(ex::BranchNode<size_t>(), ex::GetNode<size_t>());
  auto check_false = LINEAR(CHECK(size_t{0}));
  auto check_true = LINEAR(CHECK(size_t{1}));

  loop.connect_next(&branch, 0);
  branch.connect_next(&check_false, 1);
  branch.connect_next(&check_true, 0);

  branch.get_data_node()->connect_input(loop.get_data_node(), 0, 0);
  check_false.get_data_node()->connect_input(loop.get_data_node(), 0, 0);
  check_true.get_data_node()->connect_input(loop.get_data_node(), 0, 0);

  loop.start();
}
