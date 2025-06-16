#pragma once

namespace nds {

/// @brief Runtime information about type.
struct ElementTypeInfo {
  /// @brief Unique for each type.
  const size_t type_hash;

  const bool is_const : 1;
  const bool is_volatile : 1;
  const bool is_reference : 1;
  const bool is_copy_constructible : 1;

  /// @brief Check if this type can be reinterpret as another.
  bool implies(const ElementTypeInfo& info) const {
    return type_hash == info.type_hash && (
        (!info.is_reference && info.is_copy_constructible) || // can drop qualifiers after making copy
        ((!is_const || info.is_const) && (!is_volatile || info.is_volatile)) // implication prevent dropping qualifier when using references
      );
  }
};

/// @brief Abstract class for data nodes.
class DataNode {
 public:
  virtual ~DataNode() = default;

  /// @brief Starts execution of node.
  /// All inputs of current node must be connected with outputs of other nodes.
  /// If an input of this node need a result of another node's work and it's not already computed, recursively runs other data node's execution.
  virtual void act() = 0;

  /// @brief Connects output of other node to input of this node.
  /// @param src_node node whose result will be connected.
  /// @param src_index index of output in src_node.
  /// @param dest_index index of input in this node.
  /// @return true if plain types of input and output are same (without any qualifiers), connection doesn't drops const and indexes are in bounds, else false.
  virtual bool connect_input(DataNode* src_node, std::size_t src_index, std::size_t dest_index) = 0;

  /// @brief Get count of outputs of node.
  /// @return size of outputs array.
  virtual size_t outputs_size() const = 0;

  /// @brief Checks if node is already done.
  /// @return true if node is done, else false.
  virtual bool is_done() = 0;

  /// @brief Deletes result of this node's work.
  virtual void invalidate() = 0;

  /// @brief Gets specific result of work of this node by index.
  virtual void* get_result_elem(std::size_t index) = 0;

  /// @brief Gets type info of specific result of work of this node by index.
  virtual ElementTypeInfo get_result_elem_type_info(std::size_t index) = 0;
};

} // nds
