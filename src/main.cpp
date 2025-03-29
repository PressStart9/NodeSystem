#include <iostream>

#include "PrintNode.h"
#include "VariableNode.h"

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
  VariableNode<Test> a(Test{});
  VariableNode<float> b(2.2);
  VariableNode<std::string> c("3");

  PrintNode<Test, float, std::string> d;
  d.connect_input(a, 0, 0);
  d.connect_input(b, 1, 1);
  d.connect_input(c, 2, 2);

  try {
    d.run();
  } catch (const std::exception& e) {
    std::cout << e.what();
  }


  return 0;
}
