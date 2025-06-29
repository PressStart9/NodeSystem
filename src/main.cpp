#include <cassert>
#include <iostream>
#include <memory>

#include "abstract/ControlNode.h"
#include "abstract/ControlNodeWrapper.h"
#include "abstract/DataNode.h"
#include "abstract/DataNodeWrapper.h"
#include "examples/control_nodes/BranchNode.h"
#include "examples/control_nodes/ForNode.h"
#include "examples/control_nodes/LinearNode.h"
#include "examples/data_nodes/ConstantNode.h"
#include "examples/data_nodes/CounterNode.h"
#include "examples/data_nodes/EmptyNode.h"
#include "examples/data_nodes/PrintNode.h"
#include "examples/data_nodes/VariableNode.h"

#define CONST(type, value) nds::DataNodeWrapper(nds::ex::ConstantNode<type>(value))
#define VAR(type, value) nds::DataNodeWrapper(nds::ex::VariableNode<type>(value))
#define PRINT(...) nds::DataNodeWrapper(nds::ex::PrintNode<__VA_ARGS__>())

int main() {
  std::cout << std::boolalpha << std::endl;

  auto a = nds::ControlNodeWrapper(nds::ex::ForNode<size_t>(), nds::DataNodeWrapper(nds::ex::CounterNode<size_t>(10)));
  auto b = nds::ControlNodeWrapper(nds::ex::LinearNode(), PRINT(size_t));

  b.get_data_node()->connect_input(a.get_data_node(), 0, 0);
  a.connect_next(&b, 0);

  a.start();

  return 0;
}
