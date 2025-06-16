#include <memory>

#include "util/util.h"


RESET_CALL_COUNTER_EACH_TEST(DataNodeTests)

using namespace nds;

std::string variable_function() { return "string"; }

struct addition_functor {
  int operator()(const int& a, const int& b) {
    return a + b;
  }
};

int addition_function(const int& a, const int& b) {
  return a + b;
}

auto addition_lambda = [](const int& a, const int& b) {
  return a + b;
};

TEST_F(DataNodeTests, DefaultTest) {
  auto a = CONST(CallCounter, CallCounter{});
  auto f = []() { return 2.2f; };
  auto b = nds::DataNodeWrapper(f);
  auto c = nds::DataNodeWrapper(&variable_function);

  b.act();
  std::cout << *reinterpret_cast<float*>(b.get_result_elem(0)) << '\n';

  auto d = CHECK(CallCounter(), 2.2f, std::string("string"));
  d.connect_input(&a, 0, 0);
  d.connect_input(&b, 0, 1);
  d.connect_input(&c, 0, 2);

  ASSERT_FALSE(d.connect_input(&a, 0, 1));

  d.act();

  ASSERT_EQ(0, CallCounter::copy_construct_count);
  ASSERT_EQ(0, CallCounter::copy_assign_count);

  ASSERT_EQ(0, CallCounter::delete_count);
  ASSERT_EQ(0, CallCounter::delete_array_count);

  std::cout << CallCounter{} << '\n';
}

TEST_F(DataNodeTests, SuccessfulConnectTest) {
  auto a = CHECK(0, CallCounter());
  auto b = CONST(int, 0);

  ASSERT_TRUE(a.connect_input(&b, 0, 0));
}

TEST_F(DataNodeTests, TypeMismatchConnectTest) {
  auto a = CHECK(0.f, CallCounter());
  auto b = CONST(int, 0);

  ASSERT_FALSE(a.connect_input(&b, 0, 0));
}

TEST_F(DataNodeTests, DestinationOutOfRangeConnectTest) {
  auto a = CHECK(0, CallCounter());
  auto b = CONST(int, 0);

  ASSERT_FALSE(a.connect_input(&b, 0, 2));
}

TEST_F(DataNodeTests, SourceOutOfRangeConnectTest) {
  auto a = CHECK(0, CallCounter());
  auto b = CONST(int, 0);

  ASSERT_FALSE(a.connect_input(&b, 1, 0));
}

TEST_F(DataNodeTests, NoInputTest) {
  auto a = CHECK(CallCounter());

  ASSERT_THROW(a.act(), exc::no_source_error);
}

TEST_F(DataNodeTests, NoAnyInputTest) {
  auto a = CHECK(0, CallCounter());
  auto b = CONST(int, 0);

  a.connect_input(&b, 0, 0);

  ASSERT_THROW(a.act(), exc::no_source_error);
}

TEST_F(DataNodeTests, FunctorAdditionTest) {
  auto a = CONST(int, 5);
  auto b = CONST(int, 7);
  
  auto c = DataNodeWrapper(addition_functor{});
  c.connect_input(&a, 0, 0);
  c.connect_input(&b, 0, 1);
  
  auto d = CHECK(a.get_functor().get_value() + b.get_functor().get_value());
  d.connect_input(&c, 0, 0);
  d.act();
}

TEST_F(DataNodeTests, FunctionAdditionTest) {
  auto a = CONST(int, 5);
  auto b = CONST(int, 7);
  
  auto c = DataNodeWrapper(&addition_function);
  c.connect_input(&a, 0, 0);
  c.connect_input(&b, 0, 1);
  
  auto d = CHECK(a.get_functor().get_value() + b.get_functor().get_value());
  d.connect_input(&c, 0, 0);
  d.act();
}

TEST_F(DataNodeTests, LambdaAdditionTest) {
  auto a = CONST(int, 5);
  auto b = CONST(int, 7);
  
  auto c = DataNodeWrapper(addition_lambda);
  c.connect_input(&a, 0, 0);
  c.connect_input(&b, 0, 1);
  
  auto d = CHECK(a.get_functor().get_value() + b.get_functor().get_value());
  d.connect_input(&c, 0, 0);
  d.act();
}

TEST_F(DataNodeTests, SequencePassTest) {
  constexpr int chain_size = 10;

  auto a = std::make_shared<DataNodeWrapper<ex::ConstantNode<CallCounter>>>(ex::ConstantNode(CallCounter()));

  auto lam = [](const CallCounter& cc) -> const CallCounter& { return cc; };
  
  auto chain = std::array<std::shared_ptr<DataNode>, chain_size>({a});
  for (int i = 1; i < chain_size; ++i) {
    chain[i] = std::make_shared<DataNodeWrapper<decltype(lam)>>(lam);
    chain[i]->connect_input(chain[i - 1].get(), 0, 0);
  }
  
  auto b = CHECK(CallCounter());
  b.connect_input(chain.back().get(), 0, 0);
  b.act();

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
