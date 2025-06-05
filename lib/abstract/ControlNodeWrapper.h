#pragma once

#include <tuple>

#include "ControlNode.h"
#include "util/node_util.h"

namespace nds {

/// @brief Structure with information about branch execution.
struct BranchInfo {
  BranchInfo(size_t next_branch, bool break_loop = true, bool save_point = false) : next_branch(next_branch), break_loop(break_loop), save_point(save_point) {}
  /// @brief Next branch index to be executed.
  const size_t next_branch;
  /// @brief 
  const bool break_loop : 1;
  /// @copydoc ControlInfo::save_point
  const bool save_point : 1;
};

/// @brief Default class for control nodes handling.
/// To introduce new node, you should pass functor or lambda to constructor of this class.
/// @tparam ControlFunctor functor that executes as node runs.
template<typename ControlFunctor, typename DataFunctor>
class ControlNodeWrapper : public ControlNode {
 public:
  using func_t = fun::callable_func_t<ControlFunctor>;
  static constexpr size_t branches_count = std::tuple_element_t<0, fun::function_arguments_t<func_t>>::size();

  explicit ControlNodeWrapper(const ControlFunctor& functor, DataNodeWrapper<DataFunctor>* inner_node = nullptr) : functor_(functor), inner_functor_(inner_node) {}
  explicit ControlNodeWrapper(ControlFunctor&& functor, DataNodeWrapper<DataFunctor>* inner_node = nullptr) : functor_(std::move(functor)), inner_functor_(inner_node) {}

  ControlNodeWrapper(const ControlNodeWrapper& wrapper) : functor_(wrapper.functor_), inner_functor_(wrapper.inner_functor_) {}
  ControlNodeWrapper(ControlNodeWrapper&& wrapper) noexcept : functor_(std::move(wrapper.functor_)), inner_functor_(wrapper.inner_functor_) {}

  ControlNodeWrapper& operator=(const ControlNodeWrapper& wrapper) = delete;
  ControlNodeWrapper& operator=(ControlNodeWrapper&& wrapper) noexcept = delete;

  /// @copydoc ControlNode::run
  ControlInfo run() override {
    inner_functor_->act();
    BranchInfo info = functor_(inner_functor_);
    return {info.break_loop ? nullptr : branches_[info.next_branch], info.save_point};
  }

  /// @copydoc ControlNode::start
  void start() override {
    while (true) {
      inner_functor_->act();
      BranchInfo info = functor_(inner_functor_);
      if (info.break_loop) {
        return;
      }
      ControlNode* branch = branches_[info.next_branch];
      if (branch == nullptr) {
        break;
      }
      branch->start();
    } 
  }

  /// @copydoc ControlNode::connect_next
  void connect_next(ControlNode* dest_node, size_t src_index) override {
    branches_[src_index] = dest_node;
  }

 protected:
  std::array<ControlNode*, branches_count> branches_{};

  ControlFunctor functor_;
  DataNodeWrapper<DataFunctor>* inner_functor_;
};

} // nds
