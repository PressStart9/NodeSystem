#pragma once

#include <tuple>
#include <stdexcept>

namespace fun {

namespace impl {

#define TYPE_MISMATCH_THROW(Index) return std::get<Offset + Index>(t);

template<std::size_t Legth>
struct get_tuple_value_impl {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::get<Offset + 0>(t);
      case 1: return std::get<Offset + 1>(t);
      case 2: return std::get<Offset + 2>(t);
      case 3: return std::get<Offset + 3>(t);
      case 4: return std::get<Offset + 4>(t);
      case 5: return std::get<Offset + 5>(t);
      case 6: return std::get<Offset + 6>(t);
      case 7: return std::get<Offset + 7>(t);
      case 8: return std::get<Offset + 8>(t);
      case 9: return std::get<Offset + 9>(t);
      case 10: return std::get<Offset + 10>(t);
      case 11: return std::get<Offset + 11>(t);
      case 12: return std::get<Offset + 12>(t);
      case 13: return std::get<Offset + 13>(t);
      case 14: return std::get<Offset + 14>(t);
      case 15: return std::get<Offset + 15>(t);
      default: return get_tuple_value_impl<Legth - 16>::template
            value<Offset + 16>(std::forward<Tuple>(t), index - 16);
    }
  }
};

template<> struct get_tuple_value_impl<16> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::get<Offset + 0>(t);
      case 1: return std::get<Offset + 1>(t);
      case 2: return std::get<Offset + 2>(t);
      case 3: return std::get<Offset + 3>(t);
      case 4: return std::get<Offset + 4>(t);
      case 5: return std::get<Offset + 5>(t);
      case 6: return std::get<Offset + 6>(t);
      case 7: return std::get<Offset + 7>(t);
      case 8: return std::get<Offset + 8>(t);
      case 9: return std::get<Offset + 9>(t);
      case 10: return std::get<Offset + 10>(t);
      case 11: return std::get<Offset + 11>(t);
      case 12: return std::get<Offset + 12>(t);
      case 13: return std::get<Offset + 13>(t);
      case 14: return std::get<Offset + 14>(t);
      default: return std::get<Offset + 15>(t);
    }
  }
};

template<> struct get_tuple_value_impl<15> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::get<Offset + 0>(t);
      case 1: return std::get<Offset + 1>(t);
      case 2: return std::get<Offset + 2>(t);
      case 3: return std::get<Offset + 3>(t);
      case 4: return std::get<Offset + 4>(t);
      case 5: return std::get<Offset + 5>(t);
      case 6: return std::get<Offset + 6>(t);
      case 7: return std::get<Offset + 7>(t);
      case 8: return std::get<Offset + 8>(t);
      case 9: return std::get<Offset + 9>(t);
      case 10: return std::get<Offset + 10>(t);
      case 11: return std::get<Offset + 11>(t);
      case 12: return std::get<Offset + 12>(t);
      case 13: return std::get<Offset + 13>(t);
      default: return std::get<Offset + 14>(t);
    }
  }
};

template<> struct get_tuple_value_impl<14> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::get<Offset + 0>(t);
      case 1: return std::get<Offset + 1>(t);
      case 2: return std::get<Offset + 2>(t);
      case 3: return std::get<Offset + 3>(t);
      case 4: return std::get<Offset + 4>(t);
      case 5: return std::get<Offset + 5>(t);
      case 6: return std::get<Offset + 6>(t);
      case 7: return std::get<Offset + 7>(t);
      case 8: return std::get<Offset + 8>(t);
      case 9: return std::get<Offset + 9>(t);
      case 10: return std::get<Offset + 10>(t);
      case 11: return std::get<Offset + 11>(t);
      case 12: return std::get<Offset + 12>(t);
      default: return std::get<Offset + 13>(t);
    }
  }
};

template<> struct get_tuple_value_impl<13> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::get<Offset + 0>(t);
      case 1: return std::get<Offset + 1>(t);
      case 2: return std::get<Offset + 2>(t);
      case 3: return std::get<Offset + 3>(t);
      case 4: return std::get<Offset + 4>(t);
      case 5: return std::get<Offset + 5>(t);
      case 6: return std::get<Offset + 6>(t);
      case 7: return std::get<Offset + 7>(t);
      case 8: return std::get<Offset + 8>(t);
      case 9: return std::get<Offset + 9>(t);
      case 10: return std::get<Offset + 10>(t);
      case 11: return std::get<Offset + 11>(t);
      default: return std::get<Offset + 12>(t);
    }
  }
};

template<> struct get_tuple_value_impl<12> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::get<Offset + 0>(t);
      case 1: return std::get<Offset + 1>(t);
      case 2: return std::get<Offset + 2>(t);
      case 3: return std::get<Offset + 3>(t);
      case 4: return std::get<Offset + 4>(t);
      case 5: return std::get<Offset + 5>(t);
      case 6: return std::get<Offset + 6>(t);
      case 7: return std::get<Offset + 7>(t);
      case 8: return std::get<Offset + 8>(t);
      case 9: return std::get<Offset + 9>(t);
      case 10: return std::get<Offset + 10>(t);
      default: return std::get<Offset + 11>(t);
    }
  }
};

template<> struct get_tuple_value_impl<11> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::get<Offset + 0>(t);
      case 1: return std::get<Offset + 1>(t);
      case 2: return std::get<Offset + 2>(t);
      case 3: return std::get<Offset + 3>(t);
      case 4: return std::get<Offset + 4>(t);
      case 5: return std::get<Offset + 5>(t);
      case 6: return std::get<Offset + 6>(t);
      case 7: return std::get<Offset + 7>(t);
      case 8: return std::get<Offset + 8>(t);
      case 9: return std::get<Offset + 9>(t);
      default: return std::get<Offset + 10>(t);
    }
  }
};

template<> struct get_tuple_value_impl<10> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::get<Offset + 0>(t);
      case 1: return std::get<Offset + 1>(t);
      case 2: return std::get<Offset + 2>(t);
      case 3: return std::get<Offset + 3>(t);
      case 4: return std::get<Offset + 4>(t);
      case 5: return std::get<Offset + 5>(t);
      case 6: return std::get<Offset + 6>(t);
      case 7: return std::get<Offset + 7>(t);
      case 8: return std::get<Offset + 8>(t);
      default: return std::get<Offset + 9>(t);
    }
  }
};

template<> struct get_tuple_value_impl<9> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::get<Offset + 0>(t);
      case 1: return std::get<Offset + 1>(t);
      case 2: return std::get<Offset + 2>(t);
      case 3: return std::get<Offset + 3>(t);
      case 4: return std::get<Offset + 4>(t);
      case 5: return std::get<Offset + 5>(t);
      case 6: return std::get<Offset + 6>(t);
      case 7: return std::get<Offset + 7>(t);
      default: return std::get<Offset + 8>(t);
    }
  }
};

template<> struct get_tuple_value_impl<8> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::get<Offset + 0>(t);
      case 1: return std::get<Offset + 1>(t);
      case 2: return std::get<Offset + 2>(t);
      case 3: return std::get<Offset + 3>(t);
      case 4: return std::get<Offset + 4>(t);
      case 5: return std::get<Offset + 5>(t);
      case 6: return std::get<Offset + 6>(t);
      default: return std::get<Offset + 7>(t);
    }
  }
};

template<> struct get_tuple_value_impl<7> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::get<Offset + 0>(t);
      case 1: return std::get<Offset + 1>(t);
      case 2: return std::get<Offset + 2>(t);
      case 3: return std::get<Offset + 3>(t);
      case 4: return std::get<Offset + 4>(t);
      case 5: return std::get<Offset + 5>(t);
      default: return std::get<Offset + 6>(t);
    }
  }
};

template<> struct get_tuple_value_impl<6> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::get<Offset + 0>(t);
      case 1: return std::get<Offset + 1>(t);
      case 2: return std::get<Offset + 2>(t);
      case 3: return std::get<Offset + 3>(t);
      case 4: return std::get<Offset + 4>(t);
      case 5: return std::get<Offset + 5>(t);
      default: return std::get<Offset + 5>(t);
    }
  }
};

template<> struct get_tuple_value_impl<5> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::get<Offset + 0>(t);
      case 1: return std::get<Offset + 1>(t);
      case 2: return std::get<Offset + 2>(t);
      case 3: return std::get<Offset + 3>(t);
      default: return std::get<Offset + 4>(t);
    }
  }
};

template<> struct get_tuple_value_impl<4> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::get<Offset + 0>(t);
      case 1: return std::get<Offset + 1>(t);
      case 2: return std::get<Offset + 2>(t);
      default: return std::get<Offset + 3>(t);
    }
  }
};

template<> struct get_tuple_value_impl<3> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::get<Offset + 0>(t);
      case 1: return std::get<Offset + 1>(t);
      default: return std::get<Offset + 2>(t);
    }
  }
};

template<> struct get_tuple_value_impl<2> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::get<Offset + 0>(t);
      default: return std::get<Offset + 1>(t);
    }
  }
};

template<> struct get_tuple_value_impl<1> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      default: return std::get<Offset + 0>(t);
    }
  }
};

template<> struct get_tuple_value_impl<0>
{
  template <typename Tuple>
  static std::any value(Tuple&&, std::size_t) {
    return {};
  }
};

} // impl

/// @brief Get tuple element by given index.
/// Get tuple element with given runtime index.
/// For tuples with size less than or equal 16 works as switch/case, else iterates tuple with step of size 16 until finds needed block of size less than 16 it do switch case.
template <typename Tuple>
std::any get_tuple_value(Tuple&& t, std::size_t index) {
  return impl::get_tuple_value_impl<std::tuple_size_v<std::remove_reference_t<Tuple>>>::
    value(std::forward<Tuple>(t), index);
}

} // fun
