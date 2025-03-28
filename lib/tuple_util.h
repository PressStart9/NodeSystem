#pragma once

#include <tuple>
#include <stdexcept>

namespace fun {

namespace impl {

#define TYPE_MISMATCH_THROW(Index) \
  if constexpr (std::is_same_v<std::tuple_element_t<Offset + Index, std::remove_reference_t<Tuple>>, T>) { \
    return std::get<Offset + Index>(t); \
  } else { \
    throw std::invalid_argument("Type mismatch."); \
  }

template<std::size_t Legth>
struct get_tuple_value_impl {
  template <typename T, std::size_t Offset = 0, typename Tuple>
  static T& value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: TYPE_MISMATCH_THROW(0);
      case 1: TYPE_MISMATCH_THROW(1);
      case 2: TYPE_MISMATCH_THROW(2);
      case 3: TYPE_MISMATCH_THROW(3);
      case 4: TYPE_MISMATCH_THROW(4);
      case 5: TYPE_MISMATCH_THROW(5);
      case 6: TYPE_MISMATCH_THROW(6);
      case 7: TYPE_MISMATCH_THROW(7);
      case 8: TYPE_MISMATCH_THROW(8);
      case 9: TYPE_MISMATCH_THROW(9);
      case 10: TYPE_MISMATCH_THROW(10);
      case 11: TYPE_MISMATCH_THROW(11);
      case 12: TYPE_MISMATCH_THROW(12);
      case 13: TYPE_MISMATCH_THROW(13);
      case 14: TYPE_MISMATCH_THROW(14);
      case 15: TYPE_MISMATCH_THROW(15);
      default: return get_tuple_value_impl<Legth - 16>::template
            value<T, Offset + 16>(std::forward<Tuple>(t), index - 16);
    }
  }
};

template<> struct get_tuple_value_impl<16> {
  template <typename T, std::size_t Offset = 0, typename Tuple>
  static T& value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: TYPE_MISMATCH_THROW(0);
      case 1: TYPE_MISMATCH_THROW(1);
      case 2: TYPE_MISMATCH_THROW(2);
      case 3: TYPE_MISMATCH_THROW(3);
      case 4: TYPE_MISMATCH_THROW(4);
      case 5: TYPE_MISMATCH_THROW(5);
      case 6: TYPE_MISMATCH_THROW(6);
      case 7: TYPE_MISMATCH_THROW(7);
      case 8: TYPE_MISMATCH_THROW(8);
      case 9: TYPE_MISMATCH_THROW(9);
      case 10: TYPE_MISMATCH_THROW(10);
      case 11: TYPE_MISMATCH_THROW(11);
      case 12: TYPE_MISMATCH_THROW(12);
      case 13: TYPE_MISMATCH_THROW(13);
      case 14: TYPE_MISMATCH_THROW(14);
      default: TYPE_MISMATCH_THROW(15);
    }
  }
};

template<> struct get_tuple_value_impl<15> {
  template <typename T, std::size_t Offset = 0, typename Tuple>
  static T& value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: TYPE_MISMATCH_THROW(0);
      case 1: TYPE_MISMATCH_THROW(1);
      case 2: TYPE_MISMATCH_THROW(2);
      case 3: TYPE_MISMATCH_THROW(3);
      case 4: TYPE_MISMATCH_THROW(4);
      case 5: TYPE_MISMATCH_THROW(5);
      case 6: TYPE_MISMATCH_THROW(6);
      case 7: TYPE_MISMATCH_THROW(7);
      case 8: TYPE_MISMATCH_THROW(8);
      case 9: TYPE_MISMATCH_THROW(9);
      case 10: TYPE_MISMATCH_THROW(10);
      case 11: TYPE_MISMATCH_THROW(11);
      case 12: TYPE_MISMATCH_THROW(12);
      case 13: TYPE_MISMATCH_THROW(13);
      default: TYPE_MISMATCH_THROW(14);
    }
  }
};

template<> struct get_tuple_value_impl<14> {
  template <typename T, std::size_t Offset = 0, typename Tuple>
  static T& value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: TYPE_MISMATCH_THROW(0);
      case 1: TYPE_MISMATCH_THROW(1);
      case 2: TYPE_MISMATCH_THROW(2);
      case 3: TYPE_MISMATCH_THROW(3);
      case 4: TYPE_MISMATCH_THROW(4);
      case 5: TYPE_MISMATCH_THROW(5);
      case 6: TYPE_MISMATCH_THROW(6);
      case 7: TYPE_MISMATCH_THROW(7);
      case 8: TYPE_MISMATCH_THROW(8);
      case 9: TYPE_MISMATCH_THROW(9);
      case 10: TYPE_MISMATCH_THROW(10);
      case 11: TYPE_MISMATCH_THROW(11);
      case 12: TYPE_MISMATCH_THROW(12);
      default: TYPE_MISMATCH_THROW(13);
    }
  }
};

template<> struct get_tuple_value_impl<13> {
  template <typename T, std::size_t Offset = 0, typename Tuple>
  static T& value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: TYPE_MISMATCH_THROW(0);
      case 1: TYPE_MISMATCH_THROW(1);
      case 2: TYPE_MISMATCH_THROW(2);
      case 3: TYPE_MISMATCH_THROW(3);
      case 4: TYPE_MISMATCH_THROW(4);
      case 5: TYPE_MISMATCH_THROW(5);
      case 6: TYPE_MISMATCH_THROW(6);
      case 7: TYPE_MISMATCH_THROW(7);
      case 8: TYPE_MISMATCH_THROW(8);
      case 9: TYPE_MISMATCH_THROW(9);
      case 10: TYPE_MISMATCH_THROW(10);
      case 11: TYPE_MISMATCH_THROW(11);
      default: TYPE_MISMATCH_THROW(12);
    }
  }
};

template<> struct get_tuple_value_impl<12> {
  template <typename T, std::size_t Offset = 0, typename Tuple>
  static T& value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: TYPE_MISMATCH_THROW(0);
      case 1: TYPE_MISMATCH_THROW(1);
      case 2: TYPE_MISMATCH_THROW(2);
      case 3: TYPE_MISMATCH_THROW(3);
      case 4: TYPE_MISMATCH_THROW(4);
      case 5: TYPE_MISMATCH_THROW(5);
      case 6: TYPE_MISMATCH_THROW(6);
      case 7: TYPE_MISMATCH_THROW(7);
      case 8: TYPE_MISMATCH_THROW(8);
      case 9: TYPE_MISMATCH_THROW(9);
      case 10: TYPE_MISMATCH_THROW(10);
      default: TYPE_MISMATCH_THROW(11);
    }
  }
};

template<> struct get_tuple_value_impl<11> {
  template <typename T, std::size_t Offset = 0, typename Tuple>
  static T& value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: TYPE_MISMATCH_THROW(0);
      case 1: TYPE_MISMATCH_THROW(1);
      case 2: TYPE_MISMATCH_THROW(2);
      case 3: TYPE_MISMATCH_THROW(3);
      case 4: TYPE_MISMATCH_THROW(4);
      case 5: TYPE_MISMATCH_THROW(5);
      case 6: TYPE_MISMATCH_THROW(6);
      case 7: TYPE_MISMATCH_THROW(7);
      case 8: TYPE_MISMATCH_THROW(8);
      case 9: TYPE_MISMATCH_THROW(9);
      default: TYPE_MISMATCH_THROW(10);
    }
  }
};

template<> struct get_tuple_value_impl<10> {
  template <typename T, std::size_t Offset = 0, typename Tuple>
  static T& value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: TYPE_MISMATCH_THROW(0);
      case 1: TYPE_MISMATCH_THROW(1);
      case 2: TYPE_MISMATCH_THROW(2);
      case 3: TYPE_MISMATCH_THROW(3);
      case 4: TYPE_MISMATCH_THROW(4);
      case 5: TYPE_MISMATCH_THROW(5);
      case 6: TYPE_MISMATCH_THROW(6);
      case 7: TYPE_MISMATCH_THROW(7);
      case 8: TYPE_MISMATCH_THROW(8);
      default: TYPE_MISMATCH_THROW(9);
    }
  }
};

template<> struct get_tuple_value_impl<9> {
  template <typename T, std::size_t Offset = 0, typename Tuple>
  static T& value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: TYPE_MISMATCH_THROW(0);
      case 1: TYPE_MISMATCH_THROW(1);
      case 2: TYPE_MISMATCH_THROW(2);
      case 3: TYPE_MISMATCH_THROW(3);
      case 4: TYPE_MISMATCH_THROW(4);
      case 5: TYPE_MISMATCH_THROW(5);
      case 6: TYPE_MISMATCH_THROW(6);
      case 7: TYPE_MISMATCH_THROW(7);
      default: TYPE_MISMATCH_THROW(8);
    }
  }
};

template<> struct get_tuple_value_impl<8> {
  template <typename T, std::size_t Offset = 0, typename Tuple>
  static T& value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: TYPE_MISMATCH_THROW(0);
      case 1: TYPE_MISMATCH_THROW(1);
      case 2: TYPE_MISMATCH_THROW(2);
      case 3: TYPE_MISMATCH_THROW(3);
      case 4: TYPE_MISMATCH_THROW(4);
      case 5: TYPE_MISMATCH_THROW(5);
      case 6: TYPE_MISMATCH_THROW(6);
      default: TYPE_MISMATCH_THROW(7);
    }
  }
};

template<> struct get_tuple_value_impl<7> {
  template <typename T, std::size_t Offset = 0, typename Tuple>
  static T& value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: TYPE_MISMATCH_THROW(0);
      case 1: TYPE_MISMATCH_THROW(1);
      case 2: TYPE_MISMATCH_THROW(2);
      case 3: TYPE_MISMATCH_THROW(3);
      case 4: TYPE_MISMATCH_THROW(4);
      case 5: TYPE_MISMATCH_THROW(5);
      default: TYPE_MISMATCH_THROW(6);
    }
  }
};

template<> struct get_tuple_value_impl<6> {
  template <typename T, std::size_t Offset = 0, typename Tuple>
  static T& value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: TYPE_MISMATCH_THROW(0);
      case 1: TYPE_MISMATCH_THROW(1);
      case 2: TYPE_MISMATCH_THROW(2);
      case 3: TYPE_MISMATCH_THROW(3);
      case 4: TYPE_MISMATCH_THROW(4);
      case 5: TYPE_MISMATCH_THROW(5);
      default: TYPE_MISMATCH_THROW(5);
    }
  }
};

template<> struct get_tuple_value_impl<5> {
  template <typename T, std::size_t Offset = 0, typename Tuple>
  static T& value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: TYPE_MISMATCH_THROW(0);
      case 1: TYPE_MISMATCH_THROW(1);
      case 2: TYPE_MISMATCH_THROW(2);
      case 3: TYPE_MISMATCH_THROW(3);
      default: TYPE_MISMATCH_THROW(4);
    }
  }
};

template<> struct get_tuple_value_impl<4> {
  template <typename T, std::size_t Offset = 0, typename Tuple>
  static T& value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: TYPE_MISMATCH_THROW(0);
      case 1: TYPE_MISMATCH_THROW(1);
      case 2: TYPE_MISMATCH_THROW(2);
      default: TYPE_MISMATCH_THROW(3);
    }
  }
};

template<> struct get_tuple_value_impl<3> {
  template <typename T, std::size_t Offset = 0, typename Tuple>
  static T& value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: TYPE_MISMATCH_THROW(0);
      case 1: TYPE_MISMATCH_THROW(1);
      default: TYPE_MISMATCH_THROW(2);
    }
  }
};

template<> struct get_tuple_value_impl<2> {
  template <typename T, std::size_t Offset = 0, typename Tuple>
  static T& value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: TYPE_MISMATCH_THROW(0);
      default: TYPE_MISMATCH_THROW(1);
    }
  }
};

template<> struct get_tuple_value_impl<1> {
  template <typename T, std::size_t Offset = 0, typename Tuple>
  static T& value(Tuple&& t, std::size_t index) {
    switch (index) {
      default: TYPE_MISMATCH_THROW(0);
    }
  }
};

template<> struct get_tuple_value_impl<0>
{
};

} // impl

/// @brief Set tuple element by given index.
/// Set tuple element with given runtime index.
/// For tuples with size less than or equal 16 works as switch/case, else iterates tuple with step of size 16 until finds needed block of size less than 16 it do switch case.
/// @param value value to assign. Can't be "read-only location".
/// @throws std::invalid_argument with text "Type mismatch.", if T is not same with element type.
template <typename T, typename Tuple>
void set_tuple_value(Tuple&& t, std::size_t index, T&& value) {
  static_assert(!std::is_const_v<T>, "Value must be non-const.");
  impl::get_tuple_value_impl<std::tuple_size_v<std::remove_reference_t<Tuple>>>::
    template value<std::remove_reference_t<T>>(std::forward<Tuple>(t), index) = value;
}

/// @brief Get tuple element by given index.
/// Get tuple element with given runtime index.
/// For tuples with size less than or equal 16 works as switch/case, else iterates tuple with step of size 16 until finds needed block of size less than 16 it do switch case.
/// @throws std::invalid_argument with text "Type mismatch.", if T is not same with element type.
template <typename T, typename Tuple>
std::remove_reference_t<T>& get_tuple_value(Tuple&& t, std::size_t index) {
  return impl::get_tuple_value_impl<std::tuple_size_v<std::remove_reference_t<Tuple>>>::
    template value<std::remove_reference_t<T>>(std::forward<Tuple>(t), index);
}

} // fun
