#include <cassert>
#include <iostream>
#include <memory>

#include "abstract/DataNode.h"
#include "abstract/DataNodeWrapper.h"
#include "abstract/ControlNode.h"
#include "abstract/ControlNodeWrapper.h"
#include "examples/data_nodes/ConstantNode.h"
#include "examples/data_nodes/VariableNode.h"
#include "examples/data_nodes/PrintNode.h"

#define CONST(type, value) nds::DataNodeWrapper<nds::ex::ConstantNode<type>>(nds::ex::ConstantNode<type>(value))
#define VAR(type, value) nds::DataNodeWrapper<nds::ex::VariableNode<type>>(nds::ex::VariableNode<type>(value))
#define PRINT(...) nds::DataNodeWrapper(nds::ex::PrintNode<__VA_ARGS__>())

int addition_function(const int& a, const int& b) {
  return a + b;
}

int main() {
  auto a = CONST(int, 5);
  auto b = CONST(int, 7);
  
  auto c = nds::DataNodeWrapper(&addition_function);
  c.connect_input(&a, 0, 0);
  c.connect_input(&b, 0, 1);
  
  auto d = PRINT(int);
  d.connect_input(&c, 0, 0);
  d.act();

  return 0;
}
