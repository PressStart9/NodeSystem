#include <cassert>
#include <iostream>

#include <SchemeNode.h>

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

int main() {
  auto a = std::make_shared<nds::ex::VariableNode<Test>>(Test{});
  auto b = std::make_shared<nds::ex::VariableNode<float>>(2.2);
  auto c = std::make_shared<nds::ex::VariableNode<std::string>>("hello");

  std::shared_ptr<nds::Node> temp;

  nds::ex::PrintNode<Test, float, std::string> d;
  d.connect_input(a, 0, 0, temp);
  d.connect_input(b, 1, 1, temp);
  d.connect_input(c, 2, 2, temp);

  assert(!d.connect_input(a, 0, 1, temp));

  try {
    d.run();
  } catch (const std::exception& e) {
    std::cout << e.what();
  }


  return 0;
}
