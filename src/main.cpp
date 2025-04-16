#include <cassert>
#include <iostream>

#include "DataNodeWrapper.h"
#include "SchemeNode.h"
#include "ControlNode.h"

#include "examples/PrintNode.h"
#include "examples/VariableNode.h"

void* operator new(std::size_t sz)
{
  std::cout << "new\n";
  if (sz == 0) { ++sz; }
  if (void *ptr = std::malloc(sz)) { return ptr; }
  throw std::bad_alloc{};
}

void* operator new[](std::size_t sz)
{
  std::cout << "new[]\n";
  if (sz == 0) { ++sz; }
  if (void *ptr = std::malloc(sz)) { return ptr; }
  throw std::bad_alloc{};
}

struct Test {
  Test() {
    std::cout << "Construct" << '\n';
  }
  Test(const Test&) {
    std::cout << "Copy construct" << '\n';
  }
  Test(Test&&) noexcept {
    std::cout << "Move construct" << '\n';
  }
  Test& operator=(const Test&) {
    std::cout << "Copy operator" << '\n';
    return *this;
  }
  Test& operator=(Test&&) noexcept {
    std::cout << "Move operator" << '\n';
    return *this;
  }
};

std::ostream& operator<<(std::ostream& stream,
                     const Test&) {
  stream << 5;
  return stream;
}

#define VAR(type, value) std::make_shared<nds::DataNodeWrapper<nds::ex::VariableNode<type>>>(nds::ex::VariableNode<type>(value));
#define PRINT(...) std::make_shared<nds::DataNodeWrapper<nds::ex::PrintNode<__VA_ARGS__>>>(nds::ex::PrintNode<__VA_ARGS__>{});

int main() {
  auto a = VAR(Test, Test{});
  auto b = VAR(float, 2.2);
  auto c = VAR(std::string, "hello");

  auto d = PRINT(Test, float, std::string);
  d->connect_input(a, 0, 0);
  d->connect_input(b, 1, 1);
  d->connect_input(c, 2, 2);

  std::shared_ptr<nds::DataNode> temp;
  assert(!d->connect_input(a, 0, 1, temp));

  try {
    d->act();
  } catch (const std::exception& e) {
    std::cout << e.what();
  }

  return 0;
}
