#pragma once

#include <stdexcept>

namespace nds::exc {

/// @brief Error thrown if there is nothing connected to one of node inputs during node execution.
class no_source_error : public std::exception {
 public:
  no_source_error() = default;

  [[nodiscard]] const char* what() const noexcept override {
    return "All inputs of node must be connected.";
  }
};

} // nds::exc