#pragma once

#include <cstdint>
#include <iostream>

#include "CheckNode.h"

#define VAR(type, value) nds::DataNodeWrapper<nds::ex::VariableNode<type>>(nds::ex::VariableNode<type>(value))
#define CHECK(...) nds::DataNodeWrapper(nds::ex::CheckNode{__VA_ARGS__})

struct CallCounter {
  CallCounter() {
    ++construct_count;
  }
  CallCounter(const CallCounter&) {
    ++copy_construct_count;
  }
  CallCounter(CallCounter&&) noexcept {
    ++move_construct_count;
  }
  CallCounter& operator=(const CallCounter&) {
    ++copy_assign_count;
    return *this;
  }
  CallCounter& operator=(CallCounter&&) noexcept {
    ++move_assign_count;
    return *this;
  }
  ~CallCounter() {
    ++destruct_count;
  }

  void* operator new(size_t size) {
    ++new_count;
    return ::operator new(size);
  }
  void* operator new[](size_t size) {
    ++new_array_count;
    return ::operator new[](size);
  }
  void operator delete(void* ptr) {
    ++delete_count;
    return ::operator delete(ptr);
  }
  void operator delete[](void* ptr) {
    ++delete_array_count;
    return ::operator delete[](ptr);
  }

  bool operator==(const CallCounter&) const { return true; }

  static size_t construct_count;
  static size_t copy_construct_count;
  static size_t move_construct_count;
  static size_t copy_assign_count;
  static size_t move_assign_count;
  static size_t destruct_count;

  static size_t new_count;
  static size_t new_array_count;
  static size_t delete_count;
  static size_t delete_array_count;

  static void reset_count() {
    construct_count = 0;
    copy_construct_count = 0;
    move_construct_count = 0;
    copy_assign_count = 0;
    move_assign_count = 0;
    destruct_count = 0;

    new_count = 0;
    new_array_count = 0;
    delete_count = 0;
    delete_array_count = 0;
  }
};

std::ostream& operator<<(std::ostream& stream, const CallCounter&) {
  stream << "CallCounter{\n\tconstruct_count: " << CallCounter::construct_count <<
    ",\n\tcopy_construct_count: " << CallCounter::copy_construct_count <<
    ",\n\tmove_construct_count: " << CallCounter::move_construct_count <<
    ",\n\tcopy_assign_count: " << CallCounter::copy_assign_count <<
    ",\n\tmove_assign_count: " << CallCounter::move_assign_count <<
    ",\n\tdestruct_count: " << CallCounter::destruct_count <<
    ",\n\tnew_count: " << CallCounter::new_count <<
    ",\n\tnew_array_count: " << CallCounter::new_array_count <<
    ",\n\tdelete_count: " << CallCounter::delete_count <<
    ",\n\tdelete_array_count: " << CallCounter::delete_array_count << "\n}";
  return stream;
}

#define CALL_COUNTER_STATIC_INIT(fixture) \
size_t CallCounter::construct_count = 0; \
size_t CallCounter::copy_construct_count = 0; \
size_t CallCounter::move_construct_count = 0; \
size_t CallCounter::copy_assign_count = 0; \
size_t CallCounter::move_assign_count = 0; \
size_t CallCounter::destruct_count = 0; \
 \
size_t CallCounter::new_count = 0; \
size_t CallCounter::new_array_count = 0; \
size_t CallCounter::delete_count = 0; \
size_t CallCounter::delete_array_count = 0; \
 \
class DataNodeTests : public ::testing::Test { \
 protected: \
  void SetUp() override { \
    CallCounter::reset_count(); \
  } \
};
