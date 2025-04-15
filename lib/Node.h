#pragma once

#include <any>
#include <array>
#include <memory>

#include "util/business_logic_exceptions.h"
#include "util/node_util.h"
#include "util/tuple_util.h"

namespace nds {

/// @brief Abstract class for data nodes.
class DataNode {
 public:
  virtual ~DataNode() = default;

  /// @brief Starts execution of node.
  /// All inputs of current node must be connected with outputs of other nodes.
  /// If an input of this node need a result of another node's work, recursively runs other node's execution.
  virtual void act() = 0;

  /// @brief Connects output of other node to input of this node.
  /// @param src_node node whose result will be connected.
  /// @param src_index index of output in src_node.
  /// @param dest_index index of input in this node.
  /// @return true if types of input and output are same and indexes are correct, else false.
  virtual bool connect_input(std::shared_ptr<DataNode> src_node, std::size_t src_index, std::size_t dest_index) = 0;

  /// @brief Connects output of other node to input of this node.
  /// @param src_node node whose result will be connected.
  /// @param src_index index of output in src_node.
  /// @param dest_index index of input in this node.
  /// @param previous_node variable of pointer to node which will be set to previous node pointer.
  /// @return true if types of input and output are same and indexes are correct, else false.
  virtual bool connect_input(std::shared_ptr<DataNode> src_node, std::size_t src_index,
    std::size_t dest_index, std::shared_ptr<DataNode>& previous_node) = 0;

  /// @brief Deletes result of this node's work.
  virtual void invalidate() = 0;

  /// @brief Gets specific result of work of this node by index.
  virtual void* get_result_elem(std::size_t index) = 0;

  /// @brief Gets type id of specific result of work of this node by index.
  virtual size_t get_result_elem_type_id(std::size_t index) = 0;

 protected:
  struct NodeResultPointer {
    std::shared_ptr<DataNode> node = nullptr;
    std::size_t index = 0;
  };
};

} // nds
