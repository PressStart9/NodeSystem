#include <iostream>

#include "PrintNode.h"
#include "VariableNode.h"

int main() {
  VariableNode<int> a(1);
  VariableNode<float> b(2.2);
  VariableNode<std::string> c("3");

  PrintNode<int, float, std::string> d;
  d.connect_input(a, 0, 0);
  d.connect_input(b, 1, 1);
  d.connect_input(c, 2, 2);

  d.run();

  return 0;
}
