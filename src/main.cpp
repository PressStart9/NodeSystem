#include <cassert>
#include <iostream>
#include <memory>

#include "abstract/DataNodeWrapper.h"

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

#define VAR(type, value) new nds::DataNodeWrapper<nds::ex::VariableNode<type>>(nds::ex::VariableNode<type>(value));
#define PRINT(...) new nds::DataNodeWrapper<nds::ex::PrintNode<__VA_ARGS__>>(nds::ex::PrintNode<__VA_ARGS__>{});

std::string string_variable() {
  return "hello";
}

int main() {
  auto a = VAR(Test, Test{});
  auto f = []() { return 2.2f; };
  auto b = new nds::DataNodeWrapper(f);
  auto c = new nds::DataNodeWrapper<decltype(&string_variable)>(string_variable);

  auto d = PRINT(Test, float, std::string);
  d->connect_input(a, 0, 0);
  d->connect_input(b, 1, 1);
  d->connect_input(c, 2, 2);

  assert(!d->connect_input(a, 0, 1));

  try {
    d->act();
  } catch (const std::exception& e) {
    std::cout << e.what();
  }

  return 0;
}
