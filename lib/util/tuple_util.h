#pragma once

#include <cstring>
#include <functional>
#include <tuple>
#include <variant>

#include "node_util.h"

namespace nds::fun {

namespace impl {

template<size_t Index, typename Tuple>
void* get_and_collapse_refernces_impl(Tuple&& t) {
  using elem_t = typename std::tuple_element_t<Index, std::remove_reference_t<Tuple>>;
  if constexpr (is_instantiation_of_v<std::reference_wrapper, elem_t>) {
    return const_cast<std::remove_const_t<typename elem_t::type>*>(&std::get<Index>(t).get());
  } else {
    return const_cast<std::remove_const_t<elem_t>*>(&std::get<Index>(t));
  }
}

template<std::size_t Length>
struct get_tuple_value_impl {
  template <std::size_t Offset = 0, typename Tuple>
  static void* value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return get_and_collapse_refernces_impl<Offset + 0>(t);
      case 1: return get_and_collapse_refernces_impl<Offset + 1>(t);
      case 2: return get_and_collapse_refernces_impl<Offset + 2>(t);
      case 3: return get_and_collapse_refernces_impl<Offset + 3>(t);
      case 4: return get_and_collapse_refernces_impl<Offset + 4>(t);
      case 5: return get_and_collapse_refernces_impl<Offset + 5>(t);
      case 6: return get_and_collapse_refernces_impl<Offset + 6>(t);
      case 7: return get_and_collapse_refernces_impl<Offset + 7>(t);
      case 8: return get_and_collapse_refernces_impl<Offset + 8>(t);
      case 9: return get_and_collapse_refernces_impl<Offset + 9>(t);
      case 10: return get_and_collapse_refernces_impl<Offset + 10>(t);
      case 11: return get_and_collapse_refernces_impl<Offset + 11>(t);
      case 12: return get_and_collapse_refernces_impl<Offset + 12>(t);
      case 13: return get_and_collapse_refernces_impl<Offset + 13>(t);
      case 14: return get_and_collapse_refernces_impl<Offset + 14>(t);
      case 15: return get_and_collapse_refernces_impl<Offset + 15>(t);
      default: return get_tuple_value_impl<Length - 16>::template
            value<Offset + 16>(std::forward<Tuple>(t), index - 16);
    }
  }
};

template<> struct get_tuple_value_impl<16> {
  template <std::size_t Offset = 0, typename Tuple>
  static void* value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return get_and_collapse_refernces_impl<Offset + 0>(t);
      case 1: return get_and_collapse_refernces_impl<Offset + 1>(t);
      case 2: return get_and_collapse_refernces_impl<Offset + 2>(t);
      case 3: return get_and_collapse_refernces_impl<Offset + 3>(t);
      case 4: return get_and_collapse_refernces_impl<Offset + 4>(t);
      case 5: return get_and_collapse_refernces_impl<Offset + 5>(t);
      case 6: return get_and_collapse_refernces_impl<Offset + 6>(t);
      case 7: return get_and_collapse_refernces_impl<Offset + 7>(t);
      case 8: return get_and_collapse_refernces_impl<Offset + 8>(t);
      case 9: return get_and_collapse_refernces_impl<Offset + 9>(t);
      case 10: return get_and_collapse_refernces_impl<Offset + 10>(t);
      case 11: return get_and_collapse_refernces_impl<Offset + 11>(t);
      case 12: return get_and_collapse_refernces_impl<Offset + 12>(t);
      case 13: return get_and_collapse_refernces_impl<Offset + 13>(t);
      case 14: return get_and_collapse_refernces_impl<Offset + 14>(t);
      default: return get_and_collapse_refernces_impl<Offset + 15>(t);
    }
  }
};

template<> struct get_tuple_value_impl<15> {
  template <std::size_t Offset = 0, typename Tuple>
  static void* value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return get_and_collapse_refernces_impl<Offset + 0>(t);
      case 1: return get_and_collapse_refernces_impl<Offset + 1>(t);
      case 2: return get_and_collapse_refernces_impl<Offset + 2>(t);
      case 3: return get_and_collapse_refernces_impl<Offset + 3>(t);
      case 4: return get_and_collapse_refernces_impl<Offset + 4>(t);
      case 5: return get_and_collapse_refernces_impl<Offset + 5>(t);
      case 6: return get_and_collapse_refernces_impl<Offset + 6>(t);
      case 7: return get_and_collapse_refernces_impl<Offset + 7>(t);
      case 8: return get_and_collapse_refernces_impl<Offset + 8>(t);
      case 9: return get_and_collapse_refernces_impl<Offset + 9>(t);
      case 10: return get_and_collapse_refernces_impl<Offset + 10>(t);
      case 11: return get_and_collapse_refernces_impl<Offset + 11>(t);
      case 12: return get_and_collapse_refernces_impl<Offset + 12>(t);
      case 13: return get_and_collapse_refernces_impl<Offset + 13>(t);
      default: return get_and_collapse_refernces_impl<Offset + 14>(t);
    }
  }
};

template<> struct get_tuple_value_impl<14> {
  template <std::size_t Offset = 0, typename Tuple>
  static void* value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return get_and_collapse_refernces_impl<Offset + 0>(t);
      case 1: return get_and_collapse_refernces_impl<Offset + 1>(t);
      case 2: return get_and_collapse_refernces_impl<Offset + 2>(t);
      case 3: return get_and_collapse_refernces_impl<Offset + 3>(t);
      case 4: return get_and_collapse_refernces_impl<Offset + 4>(t);
      case 5: return get_and_collapse_refernces_impl<Offset + 5>(t);
      case 6: return get_and_collapse_refernces_impl<Offset + 6>(t);
      case 7: return get_and_collapse_refernces_impl<Offset + 7>(t);
      case 8: return get_and_collapse_refernces_impl<Offset + 8>(t);
      case 9: return get_and_collapse_refernces_impl<Offset + 9>(t);
      case 10: return get_and_collapse_refernces_impl<Offset + 10>(t);
      case 11: return get_and_collapse_refernces_impl<Offset + 11>(t);
      case 12: return get_and_collapse_refernces_impl<Offset + 12>(t);
      default: return get_and_collapse_refernces_impl<Offset + 13>(t);
    }
  }
};

template<> struct get_tuple_value_impl<13> {
  template <std::size_t Offset = 0, typename Tuple>
  static void* value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return get_and_collapse_refernces_impl<Offset + 0>(t);
      case 1: return get_and_collapse_refernces_impl<Offset + 1>(t);
      case 2: return get_and_collapse_refernces_impl<Offset + 2>(t);
      case 3: return get_and_collapse_refernces_impl<Offset + 3>(t);
      case 4: return get_and_collapse_refernces_impl<Offset + 4>(t);
      case 5: return get_and_collapse_refernces_impl<Offset + 5>(t);
      case 6: return get_and_collapse_refernces_impl<Offset + 6>(t);
      case 7: return get_and_collapse_refernces_impl<Offset + 7>(t);
      case 8: return get_and_collapse_refernces_impl<Offset + 8>(t);
      case 9: return get_and_collapse_refernces_impl<Offset + 9>(t);
      case 10: return get_and_collapse_refernces_impl<Offset + 10>(t);
      case 11: return get_and_collapse_refernces_impl<Offset + 11>(t);
      default: return get_and_collapse_refernces_impl<Offset + 12>(t);
    }
  }
};

template<> struct get_tuple_value_impl<12> {
  template <std::size_t Offset = 0, typename Tuple>
  static void* value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return get_and_collapse_refernces_impl<Offset + 0>(t);
      case 1: return get_and_collapse_refernces_impl<Offset + 1>(t);
      case 2: return get_and_collapse_refernces_impl<Offset + 2>(t);
      case 3: return get_and_collapse_refernces_impl<Offset + 3>(t);
      case 4: return get_and_collapse_refernces_impl<Offset + 4>(t);
      case 5: return get_and_collapse_refernces_impl<Offset + 5>(t);
      case 6: return get_and_collapse_refernces_impl<Offset + 6>(t);
      case 7: return get_and_collapse_refernces_impl<Offset + 7>(t);
      case 8: return get_and_collapse_refernces_impl<Offset + 8>(t);
      case 9: return get_and_collapse_refernces_impl<Offset + 9>(t);
      case 10: return get_and_collapse_refernces_impl<Offset + 10>(t);
      default: return get_and_collapse_refernces_impl<Offset + 11>(t);
    }
  }
};

template<> struct get_tuple_value_impl<11> {
  template <std::size_t Offset = 0, typename Tuple>
  static void* value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return get_and_collapse_refernces_impl<Offset + 0>(t);
      case 1: return get_and_collapse_refernces_impl<Offset + 1>(t);
      case 2: return get_and_collapse_refernces_impl<Offset + 2>(t);
      case 3: return get_and_collapse_refernces_impl<Offset + 3>(t);
      case 4: return get_and_collapse_refernces_impl<Offset + 4>(t);
      case 5: return get_and_collapse_refernces_impl<Offset + 5>(t);
      case 6: return get_and_collapse_refernces_impl<Offset + 6>(t);
      case 7: return get_and_collapse_refernces_impl<Offset + 7>(t);
      case 8: return get_and_collapse_refernces_impl<Offset + 8>(t);
      case 9: return get_and_collapse_refernces_impl<Offset + 9>(t);
      default: return get_and_collapse_refernces_impl<Offset + 10>(t);
    }
  }
};

template<> struct get_tuple_value_impl<10> {
  template <std::size_t Offset = 0, typename Tuple>
  static void* value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return get_and_collapse_refernces_impl<Offset + 0>(t);
      case 1: return get_and_collapse_refernces_impl<Offset + 1>(t);
      case 2: return get_and_collapse_refernces_impl<Offset + 2>(t);
      case 3: return get_and_collapse_refernces_impl<Offset + 3>(t);
      case 4: return get_and_collapse_refernces_impl<Offset + 4>(t);
      case 5: return get_and_collapse_refernces_impl<Offset + 5>(t);
      case 6: return get_and_collapse_refernces_impl<Offset + 6>(t);
      case 7: return get_and_collapse_refernces_impl<Offset + 7>(t);
      case 8: return get_and_collapse_refernces_impl<Offset + 8>(t);
      default: return get_and_collapse_refernces_impl<Offset + 9>(t);
    }
  }
};

template<> struct get_tuple_value_impl<9> {
  template <std::size_t Offset = 0, typename Tuple>
  static void* value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return get_and_collapse_refernces_impl<Offset + 0>(t);
      case 1: return get_and_collapse_refernces_impl<Offset + 1>(t);
      case 2: return get_and_collapse_refernces_impl<Offset + 2>(t);
      case 3: return get_and_collapse_refernces_impl<Offset + 3>(t);
      case 4: return get_and_collapse_refernces_impl<Offset + 4>(t);
      case 5: return get_and_collapse_refernces_impl<Offset + 5>(t);
      case 6: return get_and_collapse_refernces_impl<Offset + 6>(t);
      case 7: return get_and_collapse_refernces_impl<Offset + 7>(t);
      default: return get_and_collapse_refernces_impl<Offset + 8>(t);
    }
  }
};

template<> struct get_tuple_value_impl<8> {
  template <std::size_t Offset = 0, typename Tuple>
  static void* value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return get_and_collapse_refernces_impl<Offset + 0>(t);
      case 1: return get_and_collapse_refernces_impl<Offset + 1>(t);
      case 2: return get_and_collapse_refernces_impl<Offset + 2>(t);
      case 3: return get_and_collapse_refernces_impl<Offset + 3>(t);
      case 4: return get_and_collapse_refernces_impl<Offset + 4>(t);
      case 5: return get_and_collapse_refernces_impl<Offset + 5>(t);
      case 6: return get_and_collapse_refernces_impl<Offset + 6>(t);
      default: return get_and_collapse_refernces_impl<Offset + 7>(t);
    }
  }
};

template<> struct get_tuple_value_impl<7> {
  template <std::size_t Offset = 0, typename Tuple>
  static void* value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return get_and_collapse_refernces_impl<Offset + 0>(t);
      case 1: return get_and_collapse_refernces_impl<Offset + 1>(t);
      case 2: return get_and_collapse_refernces_impl<Offset + 2>(t);
      case 3: return get_and_collapse_refernces_impl<Offset + 3>(t);
      case 4: return get_and_collapse_refernces_impl<Offset + 4>(t);
      case 5: return get_and_collapse_refernces_impl<Offset + 5>(t);
      default: return get_and_collapse_refernces_impl<Offset + 6>(t);
    }
  }
};

template<> struct get_tuple_value_impl<6> {
  template <std::size_t Offset = 0, typename Tuple>
  static void* value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return get_and_collapse_refernces_impl<Offset + 0>(t);
      case 1: return get_and_collapse_refernces_impl<Offset + 1>(t);
      case 2: return get_and_collapse_refernces_impl<Offset + 2>(t);
      case 3: return get_and_collapse_refernces_impl<Offset + 3>(t);
      case 4: return get_and_collapse_refernces_impl<Offset + 4>(t);
      case 5: return get_and_collapse_refernces_impl<Offset + 5>(t);
      default: return get_and_collapse_refernces_impl<Offset + 5>(t);
    }
  }
};

template<> struct get_tuple_value_impl<5> {
  template <std::size_t Offset = 0, typename Tuple>
  static void* value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return get_and_collapse_refernces_impl<Offset + 0>(t);
      case 1: return get_and_collapse_refernces_impl<Offset + 1>(t);
      case 2: return get_and_collapse_refernces_impl<Offset + 2>(t);
      case 3: return get_and_collapse_refernces_impl<Offset + 3>(t);
      default: return get_and_collapse_refernces_impl<Offset + 4>(t);
    }
  }
};

template<> struct get_tuple_value_impl<4> {
  template <std::size_t Offset = 0, typename Tuple>
  static void* value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return get_and_collapse_refernces_impl<Offset + 0>(t);
      case 1: return get_and_collapse_refernces_impl<Offset + 1>(t);
      case 2: return get_and_collapse_refernces_impl<Offset + 2>(t);
      default: return get_and_collapse_refernces_impl<Offset + 3>(t);
    }
  }
};

template<> struct get_tuple_value_impl<3> {
  template <std::size_t Offset = 0, typename Tuple>
  static void* value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return get_and_collapse_refernces_impl<Offset + 0>(t);
      case 1: return get_and_collapse_refernces_impl<Offset + 1>(t);
      default: return get_and_collapse_refernces_impl<Offset + 2>(t);
    }
  }
};

template<> struct get_tuple_value_impl<2> {
  template <std::size_t Offset = 0, typename Tuple>
  static void* value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return get_and_collapse_refernces_impl<Offset + 0>(t);
      default: return get_and_collapse_refernces_impl<Offset + 1>(t);
    }
  }
};

template<> struct get_tuple_value_impl<1> {
  template <std::size_t Offset = 0, typename Tuple>
  static void* value(Tuple&& t, std::size_t index) {
    switch (index) {
      default: return get_and_collapse_refernces_impl<Offset + 0>(t);
    }
  }
};

template<> struct get_tuple_value_impl<0>
{
  template <std::size_t Offset = 0, typename Tuple>
  static void* value(Tuple&&, std::size_t) {
    throw std::out_of_range("Tuple size is less than index.");
  }
};

// Must be `inline` to have one definition and same static `x` in different translation units.
// Maybe replace with `typeid(T).hash()`?
template<typename T>
inline size_t type_id_impl() {
  static int x;
  return reinterpret_cast<std::size_t>(&x);
}

template<typename T>
ElementTypeInfo type_info_impl() {
  return { type_id_impl<std::decay_t<T>>(),
    std::is_const_v<std::remove_reference_t<T>>,
    std::is_volatile_v<std::remove_reference_t<T>>,
    std::is_reference_v<T>,
    std::is_copy_constructible_v<std::decay_t<T>>
  };
}

template<std::size_t Length>
struct get_tuple_value_type_id_impl {
  template <typename Tuple, std::size_t Offset = 0>
  static ElementTypeInfo value(std::size_t index) {
    switch (index) {
      case 0: return type_info_impl<std::tuple_element_t<Offset + 0, Tuple>>();
      case 1: return type_info_impl<std::tuple_element_t<Offset + 1, Tuple>>();
      case 2: return type_info_impl<std::tuple_element_t<Offset + 2, Tuple>>();
      case 3: return type_info_impl<std::tuple_element_t<Offset + 3, Tuple>>();
      case 4: return type_info_impl<std::tuple_element_t<Offset + 4, Tuple>>();
      case 5: return type_info_impl<std::tuple_element_t<Offset + 5, Tuple>>();
      case 6: return type_info_impl<std::tuple_element_t<Offset + 6, Tuple>>();
      case 7: return type_info_impl<std::tuple_element_t<Offset + 7, Tuple>>();
      case 8: return type_info_impl<std::tuple_element_t<Offset + 8, Tuple>>();
      case 9: return type_info_impl<std::tuple_element_t<Offset + 9, Tuple>>();
      case 10: return type_info_impl<std::tuple_element_t<Offset + 10, Tuple>>();
      case 11: return type_info_impl<std::tuple_element_t<Offset + 11, Tuple>>();
      case 12: return type_info_impl<std::tuple_element_t<Offset + 12, Tuple>>();
      case 13: return type_info_impl<std::tuple_element_t<Offset + 13, Tuple>>();
      case 14: return type_info_impl<std::tuple_element_t<Offset + 14, Tuple>>();
      case 15: return type_info_impl<std::tuple_element_t<Offset + 15, Tuple>>();
      default: return get_tuple_value_type_id_impl<Length - 16>::template
            value<Tuple, Offset + 16>(index - 16);
    }
  }
};

template<> struct get_tuple_value_type_id_impl<16> {
  template <typename Tuple, std::size_t Offset = 0>
  static ElementTypeInfo value(std::size_t index) {
    switch (index) {
      case 0: return type_info_impl<std::tuple_element_t<Offset + 0, Tuple>>();
      case 1: return type_info_impl<std::tuple_element_t<Offset + 1, Tuple>>();
      case 2: return type_info_impl<std::tuple_element_t<Offset + 2, Tuple>>();
      case 3: return type_info_impl<std::tuple_element_t<Offset + 3, Tuple>>();
      case 4: return type_info_impl<std::tuple_element_t<Offset + 4, Tuple>>();
      case 5: return type_info_impl<std::tuple_element_t<Offset + 5, Tuple>>();
      case 6: return type_info_impl<std::tuple_element_t<Offset + 6, Tuple>>();
      case 7: return type_info_impl<std::tuple_element_t<Offset + 7, Tuple>>();
      case 8: return type_info_impl<std::tuple_element_t<Offset + 8, Tuple>>();
      case 9: return type_info_impl<std::tuple_element_t<Offset + 9, Tuple>>();
      case 10: return type_info_impl<std::tuple_element_t<Offset + 10, Tuple>>();
      case 11: return type_info_impl<std::tuple_element_t<Offset + 11, Tuple>>();
      case 12: return type_info_impl<std::tuple_element_t<Offset + 12, Tuple>>();
      case 13: return type_info_impl<std::tuple_element_t<Offset + 13, Tuple>>();
      case 14: return type_info_impl<std::tuple_element_t<Offset + 14, Tuple>>();
      default: return type_info_impl<std::tuple_element_t<Offset + 15, Tuple>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<15> {
  template <typename Tuple, std::size_t Offset = 0>
  static ElementTypeInfo value(std::size_t index) {
    switch (index) {
      case 0: return type_info_impl<std::tuple_element_t<Offset + 0, Tuple>>();
      case 1: return type_info_impl<std::tuple_element_t<Offset + 1, Tuple>>();
      case 2: return type_info_impl<std::tuple_element_t<Offset + 2, Tuple>>();
      case 3: return type_info_impl<std::tuple_element_t<Offset + 3, Tuple>>();
      case 4: return type_info_impl<std::tuple_element_t<Offset + 4, Tuple>>();
      case 5: return type_info_impl<std::tuple_element_t<Offset + 5, Tuple>>();
      case 6: return type_info_impl<std::tuple_element_t<Offset + 6, Tuple>>();
      case 7: return type_info_impl<std::tuple_element_t<Offset + 7, Tuple>>();
      case 8: return type_info_impl<std::tuple_element_t<Offset + 8, Tuple>>();
      case 9: return type_info_impl<std::tuple_element_t<Offset + 9, Tuple>>();
      case 10: return type_info_impl<std::tuple_element_t<Offset + 10, Tuple>>();
      case 11: return type_info_impl<std::tuple_element_t<Offset + 11, Tuple>>();
      case 12: return type_info_impl<std::tuple_element_t<Offset + 12, Tuple>>();
      case 13: return type_info_impl<std::tuple_element_t<Offset + 13, Tuple>>();
      default: return type_info_impl<std::tuple_element_t<Offset + 14, Tuple>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<14> {
  template <typename Tuple, std::size_t Offset = 0>
  static ElementTypeInfo value(std::size_t index) {
    switch (index) {
      case 0: return type_info_impl<std::tuple_element_t<Offset + 0, Tuple>>();
      case 1: return type_info_impl<std::tuple_element_t<Offset + 1, Tuple>>();
      case 2: return type_info_impl<std::tuple_element_t<Offset + 2, Tuple>>();
      case 3: return type_info_impl<std::tuple_element_t<Offset + 3, Tuple>>();
      case 4: return type_info_impl<std::tuple_element_t<Offset + 4, Tuple>>();
      case 5: return type_info_impl<std::tuple_element_t<Offset + 5, Tuple>>();
      case 6: return type_info_impl<std::tuple_element_t<Offset + 6, Tuple>>();
      case 7: return type_info_impl<std::tuple_element_t<Offset + 7, Tuple>>();
      case 8: return type_info_impl<std::tuple_element_t<Offset + 8, Tuple>>();
      case 9: return type_info_impl<std::tuple_element_t<Offset + 9, Tuple>>();
      case 10: return type_info_impl<std::tuple_element_t<Offset + 10, Tuple>>();
      case 11: return type_info_impl<std::tuple_element_t<Offset + 11, Tuple>>();
      case 12: return type_info_impl<std::tuple_element_t<Offset + 12, Tuple>>();
      default: return type_info_impl<std::tuple_element_t<Offset + 13, Tuple>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<13> {
  template <typename Tuple, std::size_t Offset = 0>
  static ElementTypeInfo value(std::size_t index) {
    switch (index) {
      case 0: return type_info_impl<std::tuple_element_t<Offset + 0, Tuple>>();
      case 1: return type_info_impl<std::tuple_element_t<Offset + 1, Tuple>>();
      case 2: return type_info_impl<std::tuple_element_t<Offset + 2, Tuple>>();
      case 3: return type_info_impl<std::tuple_element_t<Offset + 3, Tuple>>();
      case 4: return type_info_impl<std::tuple_element_t<Offset + 4, Tuple>>();
      case 5: return type_info_impl<std::tuple_element_t<Offset + 5, Tuple>>();
      case 6: return type_info_impl<std::tuple_element_t<Offset + 6, Tuple>>();
      case 7: return type_info_impl<std::tuple_element_t<Offset + 7, Tuple>>();
      case 8: return type_info_impl<std::tuple_element_t<Offset + 8, Tuple>>();
      case 9: return type_info_impl<std::tuple_element_t<Offset + 9, Tuple>>();
      case 10: return type_info_impl<std::tuple_element_t<Offset + 10, Tuple>>();
      case 11: return type_info_impl<std::tuple_element_t<Offset + 11, Tuple>>();
      default: return type_info_impl<std::tuple_element_t<Offset + 12, Tuple>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<12> {
  template <typename Tuple, std::size_t Offset = 0>
  static ElementTypeInfo value(std::size_t index) {
    switch (index) {
      case 0: return type_info_impl<std::tuple_element_t<Offset + 0, Tuple>>();
      case 1: return type_info_impl<std::tuple_element_t<Offset + 1, Tuple>>();
      case 2: return type_info_impl<std::tuple_element_t<Offset + 2, Tuple>>();
      case 3: return type_info_impl<std::tuple_element_t<Offset + 3, Tuple>>();
      case 4: return type_info_impl<std::tuple_element_t<Offset + 4, Tuple>>();
      case 5: return type_info_impl<std::tuple_element_t<Offset + 5, Tuple>>();
      case 6: return type_info_impl<std::tuple_element_t<Offset + 6, Tuple>>();
      case 7: return type_info_impl<std::tuple_element_t<Offset + 7, Tuple>>();
      case 8: return type_info_impl<std::tuple_element_t<Offset + 8, Tuple>>();
      case 9: return type_info_impl<std::tuple_element_t<Offset + 9, Tuple>>();
      case 10: return type_info_impl<std::tuple_element_t<Offset + 10, Tuple>>();
      default: return type_info_impl<std::tuple_element_t<Offset + 11, Tuple>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<11> {
  template <typename Tuple, std::size_t Offset = 0>
  static ElementTypeInfo value(std::size_t index) {
    switch (index) {
      case 0: return type_info_impl<std::tuple_element_t<Offset + 0, Tuple>>();
      case 1: return type_info_impl<std::tuple_element_t<Offset + 1, Tuple>>();
      case 2: return type_info_impl<std::tuple_element_t<Offset + 2, Tuple>>();
      case 3: return type_info_impl<std::tuple_element_t<Offset + 3, Tuple>>();
      case 4: return type_info_impl<std::tuple_element_t<Offset + 4, Tuple>>();
      case 5: return type_info_impl<std::tuple_element_t<Offset + 5, Tuple>>();
      case 6: return type_info_impl<std::tuple_element_t<Offset + 6, Tuple>>();
      case 7: return type_info_impl<std::tuple_element_t<Offset + 7, Tuple>>();
      case 8: return type_info_impl<std::tuple_element_t<Offset + 8, Tuple>>();
      case 9: return type_info_impl<std::tuple_element_t<Offset + 9, Tuple>>();
      default: return type_info_impl<std::tuple_element_t<Offset + 10, Tuple>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<10> {
  template <typename Tuple, std::size_t Offset = 0>
  static ElementTypeInfo value(std::size_t index) {
    switch (index) {
      case 0: return type_info_impl<std::tuple_element_t<Offset + 0, Tuple>>();
      case 1: return type_info_impl<std::tuple_element_t<Offset + 1, Tuple>>();
      case 2: return type_info_impl<std::tuple_element_t<Offset + 2, Tuple>>();
      case 3: return type_info_impl<std::tuple_element_t<Offset + 3, Tuple>>();
      case 4: return type_info_impl<std::tuple_element_t<Offset + 4, Tuple>>();
      case 5: return type_info_impl<std::tuple_element_t<Offset + 5, Tuple>>();
      case 6: return type_info_impl<std::tuple_element_t<Offset + 6, Tuple>>();
      case 7: return type_info_impl<std::tuple_element_t<Offset + 7, Tuple>>();
      case 8: return type_info_impl<std::tuple_element_t<Offset + 8, Tuple>>();
      default: return type_info_impl<std::tuple_element_t<Offset + 9, Tuple>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<9> {
  template <typename Tuple, std::size_t Offset = 0>
  static ElementTypeInfo value(std::size_t index) {
    switch (index) {
      case 0: return type_info_impl<std::tuple_element_t<Offset + 0, Tuple>>();
      case 1: return type_info_impl<std::tuple_element_t<Offset + 1, Tuple>>();
      case 2: return type_info_impl<std::tuple_element_t<Offset + 2, Tuple>>();
      case 3: return type_info_impl<std::tuple_element_t<Offset + 3, Tuple>>();
      case 4: return type_info_impl<std::tuple_element_t<Offset + 4, Tuple>>();
      case 5: return type_info_impl<std::tuple_element_t<Offset + 5, Tuple>>();
      case 6: return type_info_impl<std::tuple_element_t<Offset + 6, Tuple>>();
      case 7: return type_info_impl<std::tuple_element_t<Offset + 7, Tuple>>();
      default: return type_info_impl<std::tuple_element_t<Offset + 8, Tuple>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<8> {
  template <typename Tuple, std::size_t Offset = 0>
  static ElementTypeInfo value(std::size_t index) {
    switch (index) {
      case 0: return type_info_impl<std::tuple_element_t<Offset + 0, Tuple>>();
      case 1: return type_info_impl<std::tuple_element_t<Offset + 1, Tuple>>();
      case 2: return type_info_impl<std::tuple_element_t<Offset + 2, Tuple>>();
      case 3: return type_info_impl<std::tuple_element_t<Offset + 3, Tuple>>();
      case 4: return type_info_impl<std::tuple_element_t<Offset + 4, Tuple>>();
      case 5: return type_info_impl<std::tuple_element_t<Offset + 5, Tuple>>();
      case 6: return type_info_impl<std::tuple_element_t<Offset + 6, Tuple>>();
      default: return type_info_impl<std::tuple_element_t<Offset + 7, Tuple>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<7> {
  template <typename Tuple, std::size_t Offset = 0>
  static ElementTypeInfo value(std::size_t index) {
    switch (index) {
      case 0: return type_info_impl<std::tuple_element_t<Offset + 0, Tuple>>();
      case 1: return type_info_impl<std::tuple_element_t<Offset + 1, Tuple>>();
      case 2: return type_info_impl<std::tuple_element_t<Offset + 2, Tuple>>();
      case 3: return type_info_impl<std::tuple_element_t<Offset + 3, Tuple>>();
      case 4: return type_info_impl<std::tuple_element_t<Offset + 4, Tuple>>();
      case 5: return type_info_impl<std::tuple_element_t<Offset + 5, Tuple>>();
      default: return type_info_impl<std::tuple_element_t<Offset + 6, Tuple>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<6> {
  template <typename Tuple, std::size_t Offset = 0>
  static ElementTypeInfo value(std::size_t index) {
    switch (index) {
      case 0: return type_info_impl<std::tuple_element_t<Offset + 0, Tuple>>();
      case 1: return type_info_impl<std::tuple_element_t<Offset + 1, Tuple>>();
      case 2: return type_info_impl<std::tuple_element_t<Offset + 2, Tuple>>();
      case 3: return type_info_impl<std::tuple_element_t<Offset + 3, Tuple>>();
      case 4: return type_info_impl<std::tuple_element_t<Offset + 4, Tuple>>();
      case 5: return type_info_impl<std::tuple_element_t<Offset + 5, Tuple>>();
      default: return type_info_impl<std::tuple_element_t<Offset + 5, Tuple>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<5> {
  template <typename Tuple, std::size_t Offset = 0>
  static ElementTypeInfo value(std::size_t index) {
    switch (index) {
      case 0: return type_info_impl<std::tuple_element_t<Offset + 0, Tuple>>();
      case 1: return type_info_impl<std::tuple_element_t<Offset + 1, Tuple>>();
      case 2: return type_info_impl<std::tuple_element_t<Offset + 2, Tuple>>();
      case 3: return type_info_impl<std::tuple_element_t<Offset + 3, Tuple>>();
      default: return type_info_impl<std::tuple_element_t<Offset + 4, Tuple>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<4> {
  template <typename Tuple, std::size_t Offset = 0>
  static ElementTypeInfo value(std::size_t index) {
    switch (index) {
      case 0: return type_info_impl<std::tuple_element_t<Offset + 0, Tuple>>();
      case 1: return type_info_impl<std::tuple_element_t<Offset + 1, Tuple>>();
      case 2: return type_info_impl<std::tuple_element_t<Offset + 2, Tuple>>();
      default: return type_info_impl<std::tuple_element_t<Offset + 3, Tuple>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<3> {
  template <typename Tuple, std::size_t Offset = 0>
  static ElementTypeInfo value(std::size_t index) {
    switch (index) {
      case 0: return type_info_impl<std::tuple_element_t<Offset + 0, Tuple>>();
      case 1: return type_info_impl<std::tuple_element_t<Offset + 1, Tuple>>();
      default: return type_info_impl<std::tuple_element_t<Offset + 2, Tuple>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<2> {
  template <typename Tuple, std::size_t Offset = 0>
  static ElementTypeInfo value(std::size_t index) {
    switch (index) {
      case 0: return type_info_impl<std::tuple_element_t<Offset + 0, Tuple>>();
      default: return type_info_impl<std::tuple_element_t<Offset + 1, Tuple>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<1> {
  template <typename Tuple, std::size_t Offset = 0>
  static ElementTypeInfo value(std::size_t index) {
    switch (index) {
      default: return type_info_impl<std::tuple_element_t<Offset + 0, Tuple>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<0>
{
  template <typename Tuple>
  static ElementTypeInfo value(std::size_t) {
    throw std::out_of_range("Tuple size is less than index.");
  }
};

} // impl

/// @brief Get tuple element type info by given index.
/// `type_id` guaranteed to be unique for `std::decay` of type.
/// For tuples with size less than or equal 16 works as switch/case, else iterates tuple with step of size 16 until finds needed block of size less than 16 and do switch case.
template <typename Tuple>
ElementTypeInfo get_tuple_value_type_info(std::size_t index) {
  return impl::get_tuple_value_type_id_impl<std::tuple_size_v<Tuple>>::
    template value<Tuple>(index);
}

/// @brief Get tuple element pointer by given index.
/// For tuples with size less than or equal 16 works as switch/case, else iterates tuple with step of size 16 until finds needed block of size less than 16 and do switch case.
/// If tuple stores `std::reference_wrapper`, return pointer to original object.
/// @warning Pointer drops const qualifier.
template <typename Tuple>
void* get_tuple_value(Tuple&& t, std::size_t index) {
  return impl::get_tuple_value_impl<std::tuple_size_v<std::remove_reference_t<Tuple>>>::
    value(std::forward<Tuple>(t), index);
}

} // nds::fun
