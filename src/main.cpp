#include <iostream>

#include "NodeExample.h"

int main() {
  NodeExample a;
  a.result = std::make_tuple(1.1f, 2, std::string("7"));

  NodeExample b;
  b.inputs = { nds::Node::NodeResultPointer{ &a, 2 }, { &a, 0 }, { &a, 1 } };

  b.run();

  return 0;
}
