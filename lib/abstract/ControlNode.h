#pragma once


namespace nds {

class ControlNode;

/// @brief Structure with information about flow execution for manager.
struct ControlInfo {
  ControlInfo() = default;
  ControlInfo(ControlNode* next_node) : next_node(next_node) {}
  ControlInfo(ControlNode* next_node, bool save_point) : next_node(next_node), save_point(save_point) {}
  /// @brief Next node to be executed.
  /// `nullptr` if node is end of branch.
  const ControlNode* next_node = nullptr;
  /// @brief Loop flag.
  /// `true` if node is loop and manager should return to it after branch end.
  const bool save_point = false;
};

/// @brief Abstract class for control nodes.
class ControlNode {
 public:
  virtual ~ControlNode() = default;

  /// @brief Executes this node.
  /// @return node that must be run after this. nullptr if this is end point.
  virtual ControlInfo run() = 0;

  /// @brief Transfers control over node execution to node chain starting at this one.
  /// Automatically calls next node if it exists.
  virtual void start() = 0;

  /// @brief Get inner data node. 
  virtual DataNode* get_data_node() = 0;

  /// @brief Connects node to one of branches of this node.
  /// @param dest_node node that can be run after running this node.
  /// @param src_index index of branch.
  /// @return `false` if src_index is out of range.
  virtual bool connect_next(ControlNode* dest_node, size_t src_index) = 0;
};

} // nds
