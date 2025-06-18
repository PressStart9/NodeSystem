#pragma once

#include <tuple>

#include "ControlNode.h"
#include "DataNodeWrapper.h"
#include "util/node_util.h"

namespace nds {

/// @brief Structure with information about branch execution.
struct BranchInfo {
  BranchInfo(size_t next_branch, bool break_loop = false, bool save_point = false) : next_branch(next_branch), break_loop(break_loop), save_point(save_point) {}
  /// @brief Next branch index to be executed.
  const size_t next_branch;
  /// @brief Skip flag.
  /// `true` if next node must be skipped.
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
  using decay_control_functor_t = ControlFunctor;
  using func_t = fun::callable_func_t<decay_control_functor_t>;
  static constexpr size_t branches_count = decay_control_functor_t::size;

  template<typename CF, typename DF>
  explicit ControlNodeWrapper(CF&& functor, DF&& inner_node) : functor_(std::forward<CF>(functor)), inner_functor_(std::forward<DF>(inner_node)) {}

  ControlNodeWrapper(const ControlNodeWrapper& wrapper) : functor_(wrapper.functor_), inner_functor_(wrapper.inner_functor_) {}
  ControlNodeWrapper(ControlNodeWrapper&& wrapper) noexcept : functor_(std::move(wrapper.functor_)), inner_functor_(wrapper.inner_functor_) {}

  ControlNodeWrapper& operator=(const ControlNodeWrapper& wrapper) = delete;
  ControlNodeWrapper& operator=(ControlNodeWrapper&& wrapper) noexcept = delete;

  /// @copydoc ControlNode::run
  ControlInfo run() override {
    inner_functor_.act();
    BranchInfo info = functor_(&inner_functor_);
    return {info.break_loop ? nullptr : branches_[info.next_branch], info.save_point};
  }

  /// @copydoc ControlNode::start
  void start() override {
    while (true) {
      BranchInfo info = functor_(&inner_functor_);
      if (info.break_loop) {
        return;
      }
      ControlNode* branch = branches_[info.next_branch];
      if (branch != nullptr) {
        branch->start();
      }
      inner_functor_.act();
      if (!info.save_point) {
        return;
      }
    } 
  }

  DataNode* get_data_node() override{
    return &inner_functor_;
  }

  /// @copydoc ControlNode::connect_next
  void connect_next(ControlNode* dest_node, size_t src_index) override {
    branches_[src_index] = dest_node;
  }

 protected:
  std::array<ControlNode*, branches_count> branches_{};

  decay_control_functor_t functor_;
  DataNodeWrapper<DataFunctor> inner_functor_;
};

// Deduction guide
template<typename CF, typename DFW>
ControlNodeWrapper(CF&&, DFW&&) -> ControlNodeWrapper<std::decay_t<CF>, typename std::decay_t<DFW>::decay_data_functor_t>;

} // nds
