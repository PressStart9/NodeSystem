#pragma once

#include <any>
#include <functional>
#include <tuple>

namespace nds::fun {

namespace impl {

template<std::size_t Legth>
struct get_tuple_value_impl {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::ref(std::get<Offset + 0>(t));
      case 1: return std::ref(std::get<Offset + 1>(t));
      case 2: return std::ref(std::get<Offset + 2>(t));
      case 3: return std::ref(std::get<Offset + 3>(t));
      case 4: return std::ref(std::get<Offset + 4>(t));
      case 5: return std::ref(std::get<Offset + 5>(t));
      case 6: return std::ref(std::get<Offset + 6>(t));
      case 7: return std::ref(std::get<Offset + 7>(t));
      case 8: return std::ref(std::get<Offset + 8>(t));
      case 9: return std::ref(std::get<Offset + 9>(t));
      case 10: return std::ref(std::get<Offset + 10>(t));
      case 11: return std::ref(std::get<Offset + 11>(t));
      case 12: return std::ref(std::get<Offset + 12>(t));
      case 13: return std::ref(std::get<Offset + 13>(t));
      case 14: return std::ref(std::get<Offset + 14>(t));
      case 15: return std::ref(std::get<Offset + 15>(t));
      default: return get_tuple_value_impl<Legth - 16>::template
            value<Offset + 16>(std::forward<Tuple>(t), index - 16);
    }
  }
};

template<> struct get_tuple_value_impl<16> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::ref(std::get<Offset + 0>(t));
      case 1: return std::ref(std::get<Offset + 1>(t));
      case 2: return std::ref(std::get<Offset + 2>(t));
      case 3: return std::ref(std::get<Offset + 3>(t));
      case 4: return std::ref(std::get<Offset + 4>(t));
      case 5: return std::ref(std::get<Offset + 5>(t));
      case 6: return std::ref(std::get<Offset + 6>(t));
      case 7: return std::ref(std::get<Offset + 7>(t));
      case 8: return std::ref(std::get<Offset + 8>(t));
      case 9: return std::ref(std::get<Offset + 9>(t));
      case 10: return std::ref(std::get<Offset + 10>(t));
      case 11: return std::ref(std::get<Offset + 11>(t));
      case 12: return std::ref(std::get<Offset + 12>(t));
      case 13: return std::ref(std::get<Offset + 13>(t));
      case 14: return std::ref(std::get<Offset + 14>(t));
      default: return std::ref(std::get<Offset + 15>(t));
    }
  }
};

template<> struct get_tuple_value_impl<15> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::ref(std::get<Offset + 0>(t));
      case 1: return std::ref(std::get<Offset + 1>(t));
      case 2: return std::ref(std::get<Offset + 2>(t));
      case 3: return std::ref(std::get<Offset + 3>(t));
      case 4: return std::ref(std::get<Offset + 4>(t));
      case 5: return std::ref(std::get<Offset + 5>(t));
      case 6: return std::ref(std::get<Offset + 6>(t));
      case 7: return std::ref(std::get<Offset + 7>(t));
      case 8: return std::ref(std::get<Offset + 8>(t));
      case 9: return std::ref(std::get<Offset + 9>(t));
      case 10: return std::ref(std::get<Offset + 10>(t));
      case 11: return std::ref(std::get<Offset + 11>(t));
      case 12: return std::ref(std::get<Offset + 12>(t));
      case 13: return std::ref(std::get<Offset + 13>(t));
      default: return std::ref(std::get<Offset + 14>(t));
    }
  }
};

template<> struct get_tuple_value_impl<14> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::ref(std::get<Offset + 0>(t));
      case 1: return std::ref(std::get<Offset + 1>(t));
      case 2: return std::ref(std::get<Offset + 2>(t));
      case 3: return std::ref(std::get<Offset + 3>(t));
      case 4: return std::ref(std::get<Offset + 4>(t));
      case 5: return std::ref(std::get<Offset + 5>(t));
      case 6: return std::ref(std::get<Offset + 6>(t));
      case 7: return std::ref(std::get<Offset + 7>(t));
      case 8: return std::ref(std::get<Offset + 8>(t));
      case 9: return std::ref(std::get<Offset + 9>(t));
      case 10: return std::ref(std::get<Offset + 10>(t));
      case 11: return std::ref(std::get<Offset + 11>(t));
      case 12: return std::ref(std::get<Offset + 12>(t));
      default: return std::ref(std::get<Offset + 13>(t));
    }
  }
};

template<> struct get_tuple_value_impl<13> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::ref(std::get<Offset + 0>(t));
      case 1: return std::ref(std::get<Offset + 1>(t));
      case 2: return std::ref(std::get<Offset + 2>(t));
      case 3: return std::ref(std::get<Offset + 3>(t));
      case 4: return std::ref(std::get<Offset + 4>(t));
      case 5: return std::ref(std::get<Offset + 5>(t));
      case 6: return std::ref(std::get<Offset + 6>(t));
      case 7: return std::ref(std::get<Offset + 7>(t));
      case 8: return std::ref(std::get<Offset + 8>(t));
      case 9: return std::ref(std::get<Offset + 9>(t));
      case 10: return std::ref(std::get<Offset + 10>(t));
      case 11: return std::ref(std::get<Offset + 11>(t));
      default: return std::ref(std::get<Offset + 12>(t));
    }
  }
};

template<> struct get_tuple_value_impl<12> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::ref(std::get<Offset + 0>(t));
      case 1: return std::ref(std::get<Offset + 1>(t));
      case 2: return std::ref(std::get<Offset + 2>(t));
      case 3: return std::ref(std::get<Offset + 3>(t));
      case 4: return std::ref(std::get<Offset + 4>(t));
      case 5: return std::ref(std::get<Offset + 5>(t));
      case 6: return std::ref(std::get<Offset + 6>(t));
      case 7: return std::ref(std::get<Offset + 7>(t));
      case 8: return std::ref(std::get<Offset + 8>(t));
      case 9: return std::ref(std::get<Offset + 9>(t));
      case 10: return std::ref(std::get<Offset + 10>(t));
      default: return std::ref(std::get<Offset + 11>(t));
    }
  }
};

template<> struct get_tuple_value_impl<11> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::ref(std::get<Offset + 0>(t));
      case 1: return std::ref(std::get<Offset + 1>(t));
      case 2: return std::ref(std::get<Offset + 2>(t));
      case 3: return std::ref(std::get<Offset + 3>(t));
      case 4: return std::ref(std::get<Offset + 4>(t));
      case 5: return std::ref(std::get<Offset + 5>(t));
      case 6: return std::ref(std::get<Offset + 6>(t));
      case 7: return std::ref(std::get<Offset + 7>(t));
      case 8: return std::ref(std::get<Offset + 8>(t));
      case 9: return std::ref(std::get<Offset + 9>(t));
      default: return std::ref(std::get<Offset + 10>(t));
    }
  }
};

template<> struct get_tuple_value_impl<10> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::ref(std::get<Offset + 0>(t));
      case 1: return std::ref(std::get<Offset + 1>(t));
      case 2: return std::ref(std::get<Offset + 2>(t));
      case 3: return std::ref(std::get<Offset + 3>(t));
      case 4: return std::ref(std::get<Offset + 4>(t));
      case 5: return std::ref(std::get<Offset + 5>(t));
      case 6: return std::ref(std::get<Offset + 6>(t));
      case 7: return std::ref(std::get<Offset + 7>(t));
      case 8: return std::ref(std::get<Offset + 8>(t));
      default: return std::ref(std::get<Offset + 9>(t));
    }
  }
};

template<> struct get_tuple_value_impl<9> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::ref(std::get<Offset + 0>(t));
      case 1: return std::ref(std::get<Offset + 1>(t));
      case 2: return std::ref(std::get<Offset + 2>(t));
      case 3: return std::ref(std::get<Offset + 3>(t));
      case 4: return std::ref(std::get<Offset + 4>(t));
      case 5: return std::ref(std::get<Offset + 5>(t));
      case 6: return std::ref(std::get<Offset + 6>(t));
      case 7: return std::ref(std::get<Offset + 7>(t));
      default: return std::ref(std::get<Offset + 8>(t));
    }
  }
};

template<> struct get_tuple_value_impl<8> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::ref(std::get<Offset + 0>(t));
      case 1: return std::ref(std::get<Offset + 1>(t));
      case 2: return std::ref(std::get<Offset + 2>(t));
      case 3: return std::ref(std::get<Offset + 3>(t));
      case 4: return std::ref(std::get<Offset + 4>(t));
      case 5: return std::ref(std::get<Offset + 5>(t));
      case 6: return std::ref(std::get<Offset + 6>(t));
      default: return std::ref(std::get<Offset + 7>(t));
    }
  }
};

template<> struct get_tuple_value_impl<7> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::ref(std::get<Offset + 0>(t));
      case 1: return std::ref(std::get<Offset + 1>(t));
      case 2: return std::ref(std::get<Offset + 2>(t));
      case 3: return std::ref(std::get<Offset + 3>(t));
      case 4: return std::ref(std::get<Offset + 4>(t));
      case 5: return std::ref(std::get<Offset + 5>(t));
      default: return std::ref(std::get<Offset + 6>(t));
    }
  }
};

template<> struct get_tuple_value_impl<6> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::ref(std::get<Offset + 0>(t));
      case 1: return std::ref(std::get<Offset + 1>(t));
      case 2: return std::ref(std::get<Offset + 2>(t));
      case 3: return std::ref(std::get<Offset + 3>(t));
      case 4: return std::ref(std::get<Offset + 4>(t));
      case 5: return std::ref(std::get<Offset + 5>(t));
      default: return std::ref(std::get<Offset + 5>(t));
    }
  }
};

template<> struct get_tuple_value_impl<5> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::ref(std::get<Offset + 0>(t));
      case 1: return std::ref(std::get<Offset + 1>(t));
      case 2: return std::ref(std::get<Offset + 2>(t));
      case 3: return std::ref(std::get<Offset + 3>(t));
      default: return std::ref(std::get<Offset + 4>(t));
    }
  }
};

template<> struct get_tuple_value_impl<4> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::ref(std::get<Offset + 0>(t));
      case 1: return std::ref(std::get<Offset + 1>(t));
      case 2: return std::ref(std::get<Offset + 2>(t));
      default: return std::ref(std::get<Offset + 3>(t));
    }
  }
};

template<> struct get_tuple_value_impl<3> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::ref(std::get<Offset + 0>(t));
      case 1: return std::ref(std::get<Offset + 1>(t));
      default: return std::ref(std::get<Offset + 2>(t));
    }
  }
};

template<> struct get_tuple_value_impl<2> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      case 0: return std::ref(std::get<Offset + 0>(t));
      default: return std::ref(std::get<Offset + 1>(t));
    }
  }
};

template<> struct get_tuple_value_impl<1> {
  template <std::size_t Offset = 0, typename Tuple>
  static std::any value(Tuple&& t, std::size_t index) {
    switch (index) {
      default: return std::ref(std::get<Offset + 0>(t));
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

template<typename T>
std::size_t type_id_impl() {
  static int x;
  return reinterpret_cast<std::size_t>(&x);
}

template<std::size_t Legth>
struct get_tuple_value_type_id_impl {
  template <typename Tuple, std::size_t Offset = 0>
  static std::size_t value(std::size_t index) {
    switch (index) {
      case 0: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 0, Tuple>>>>();
      case 1: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 1, Tuple>>>>();
      case 2: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 2, Tuple>>>>();
      case 3: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 3, Tuple>>>>();
      case 4: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 4, Tuple>>>>();
      case 5: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 5, Tuple>>>>();
      case 6: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 6, Tuple>>>>();
      case 7: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 7, Tuple>>>>();
      case 8: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 8, Tuple>>>>();
      case 9: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 9, Tuple>>>>();
      case 10: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 10, Tuple>>>>();
      case 11: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 11, Tuple>>>>();
      case 12: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 12, Tuple>>>>();
      case 13: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 13, Tuple>>>>();
      case 14: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 14, Tuple>>>>();
      case 15: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 15, Tuple>>>>();
      default: return get_tuple_value_type_id_impl<Legth - 16>::template
            value<Tuple, Offset + 16>(index - 16);
    }
  }
};

template<> struct get_tuple_value_type_id_impl<16> {
  template <typename Tuple, std::size_t Offset = 0>
  static std::size_t value(std::size_t index) {
    switch (index) {
      case 0: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 0, Tuple>>>>();
      case 1: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 1, Tuple>>>>();
      case 2: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 2, Tuple>>>>();
      case 3: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 3, Tuple>>>>();
      case 4: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 4, Tuple>>>>();
      case 5: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 5, Tuple>>>>();
      case 6: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 6, Tuple>>>>();
      case 7: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 7, Tuple>>>>();
      case 8: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 8, Tuple>>>>();
      case 9: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 9, Tuple>>>>();
      case 10: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 10, Tuple>>>>();
      case 11: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 11, Tuple>>>>();
      case 12: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 12, Tuple>>>>();
      case 13: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 13, Tuple>>>>();
      case 14: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 14, Tuple>>>>();
      default: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 15, Tuple>>>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<15> {
  template <typename Tuple, std::size_t Offset = 0>
  static std::size_t value(std::size_t index) {
    switch (index) {
      case 0: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 0, Tuple>>>>();
      case 1: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 1, Tuple>>>>();
      case 2: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 2, Tuple>>>>();
      case 3: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 3, Tuple>>>>();
      case 4: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 4, Tuple>>>>();
      case 5: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 5, Tuple>>>>();
      case 6: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 6, Tuple>>>>();
      case 7: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 7, Tuple>>>>();
      case 8: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 8, Tuple>>>>();
      case 9: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 9, Tuple>>>>();
      case 10: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 10, Tuple>>>>();
      case 11: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 11, Tuple>>>>();
      case 12: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 12, Tuple>>>>();
      case 13: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 13, Tuple>>>>();
      default: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 14, Tuple>>>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<14> {
  template <typename Tuple, std::size_t Offset = 0>
  static std::size_t value(std::size_t index) {
    switch (index) {
      case 0: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 0, Tuple>>>>();
      case 1: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 1, Tuple>>>>();
      case 2: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 2, Tuple>>>>();
      case 3: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 3, Tuple>>>>();
      case 4: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 4, Tuple>>>>();
      case 5: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 5, Tuple>>>>();
      case 6: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 6, Tuple>>>>();
      case 7: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 7, Tuple>>>>();
      case 8: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 8, Tuple>>>>();
      case 9: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 9, Tuple>>>>();
      case 10: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 10, Tuple>>>>();
      case 11: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 11, Tuple>>>>();
      case 12: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 12, Tuple>>>>();
      default: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 13, Tuple>>>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<13> {
  template <typename Tuple, std::size_t Offset = 0>
  static std::size_t value(std::size_t index) {
    switch (index) {
      case 0: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 0, Tuple>>>>();
      case 1: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 1, Tuple>>>>();
      case 2: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 2, Tuple>>>>();
      case 3: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 3, Tuple>>>>();
      case 4: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 4, Tuple>>>>();
      case 5: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 5, Tuple>>>>();
      case 6: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 6, Tuple>>>>();
      case 7: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 7, Tuple>>>>();
      case 8: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 8, Tuple>>>>();
      case 9: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 9, Tuple>>>>();
      case 10: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 10, Tuple>>>>();
      case 11: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 11, Tuple>>>>();
      default: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 12, Tuple>>>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<12> {
  template <typename Tuple, std::size_t Offset = 0>
  static std::size_t value(std::size_t index) {
    switch (index) {
      case 0: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 0, Tuple>>>>();
      case 1: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 1, Tuple>>>>();
      case 2: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 2, Tuple>>>>();
      case 3: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 3, Tuple>>>>();
      case 4: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 4, Tuple>>>>();
      case 5: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 5, Tuple>>>>();
      case 6: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 6, Tuple>>>>();
      case 7: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 7, Tuple>>>>();
      case 8: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 8, Tuple>>>>();
      case 9: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 9, Tuple>>>>();
      case 10: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 10, Tuple>>>>();
      default: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 11, Tuple>>>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<11> {
  template <typename Tuple, std::size_t Offset = 0>
  static std::size_t value(std::size_t index) {
    switch (index) {
      case 0: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 0, Tuple>>>>();
      case 1: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 1, Tuple>>>>();
      case 2: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 2, Tuple>>>>();
      case 3: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 3, Tuple>>>>();
      case 4: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 4, Tuple>>>>();
      case 5: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 5, Tuple>>>>();
      case 6: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 6, Tuple>>>>();
      case 7: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 7, Tuple>>>>();
      case 8: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 8, Tuple>>>>();
      case 9: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 9, Tuple>>>>();
      default: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 10, Tuple>>>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<10> {
  template <typename Tuple, std::size_t Offset = 0>
  static std::size_t value(std::size_t index) {
    switch (index) {
      case 0: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 0, Tuple>>>>();
      case 1: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 1, Tuple>>>>();
      case 2: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 2, Tuple>>>>();
      case 3: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 3, Tuple>>>>();
      case 4: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 4, Tuple>>>>();
      case 5: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 5, Tuple>>>>();
      case 6: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 6, Tuple>>>>();
      case 7: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 7, Tuple>>>>();
      case 8: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 8, Tuple>>>>();
      default: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 9, Tuple>>>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<9> {
  template <typename Tuple, std::size_t Offset = 0>
  static std::size_t value(std::size_t index) {
    switch (index) {
      case 0: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 0, Tuple>>>>();
      case 1: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 1, Tuple>>>>();
      case 2: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 2, Tuple>>>>();
      case 3: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 3, Tuple>>>>();
      case 4: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 4, Tuple>>>>();
      case 5: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 5, Tuple>>>>();
      case 6: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 6, Tuple>>>>();
      case 7: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 7, Tuple>>>>();
      default: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 8, Tuple>>>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<8> {
  template <typename Tuple, std::size_t Offset = 0>
  static std::size_t value(std::size_t index) {
    switch (index) {
      case 0: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 0, Tuple>>>>();
      case 1: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 1, Tuple>>>>();
      case 2: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 2, Tuple>>>>();
      case 3: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 3, Tuple>>>>();
      case 4: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 4, Tuple>>>>();
      case 5: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 5, Tuple>>>>();
      case 6: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 6, Tuple>>>>();
      default: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 7, Tuple>>>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<7> {
  template <typename Tuple, std::size_t Offset = 0>
  static std::size_t value(std::size_t index) {
    switch (index) {
      case 0: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 0, Tuple>>>>();
      case 1: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 1, Tuple>>>>();
      case 2: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 2, Tuple>>>>();
      case 3: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 3, Tuple>>>>();
      case 4: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 4, Tuple>>>>();
      case 5: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 5, Tuple>>>>();
      default: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 6, Tuple>>>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<6> {
  template <typename Tuple, std::size_t Offset = 0>
  static std::size_t value(std::size_t index) {
    switch (index) {
      case 0: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 0, Tuple>>>>();
      case 1: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 1, Tuple>>>>();
      case 2: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 2, Tuple>>>>();
      case 3: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 3, Tuple>>>>();
      case 4: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 4, Tuple>>>>();
      case 5: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 5, Tuple>>>>();
      default: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 5, Tuple>>>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<5> {
  template <typename Tuple, std::size_t Offset = 0>
  static std::size_t value(std::size_t index) {
    switch (index) {
      case 0: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 0, Tuple>>>>();
      case 1: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 1, Tuple>>>>();
      case 2: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 2, Tuple>>>>();
      case 3: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 3, Tuple>>>>();
      default: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 4, Tuple>>>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<4> {
  template <typename Tuple, std::size_t Offset = 0>
  static std::size_t value(std::size_t index) {
    switch (index) {
      case 0: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 0, Tuple>>>>();
      case 1: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 1, Tuple>>>>();
      case 2: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 2, Tuple>>>>();
      default: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 3, Tuple>>>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<3> {
  template <typename Tuple, std::size_t Offset = 0>
  static std::size_t value(std::size_t index) {
    switch (index) {
      case 0: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 0, Tuple>>>>();
      case 1: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 1, Tuple>>>>();
      default: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 2, Tuple>>>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<2> {
  template <typename Tuple, std::size_t Offset = 0>
  static std::size_t value(std::size_t index) {
    switch (index) {
      case 0: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 0, Tuple>>>>();
      default: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 1, Tuple>>>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<1> {
  template <typename Tuple, std::size_t Offset = 0>
  static std::size_t value(std::size_t index) {
    switch (index) {
      default: return type_id_impl<std::remove_cv_t<std::remove_reference_t<std::tuple_element_t<Offset + 0, Tuple>>>>();
    }
  }
};

template<> struct get_tuple_value_type_id_impl<0>
{
  template <typename Tuple>
  static size_t value(std::size_t) {
    return type_id_impl<void>();
  }
};

template<typename TResult>
struct parse_tuple_impl {
  using result_t = std::tuple<TResult>;
};

template<>
struct parse_tuple_impl<void> {
  using result_t = std::tuple<>;
};

template<typename... TResults>
struct parse_tuple_impl<std::tuple<TResults...>> {
  using result_t = std::tuple<TResults...>;
};

template<typename TFunction>
struct function_signature_impl;

template<typename TResult, typename TClassPart, typename... TArgs>
struct function_signature_impl<TResult(TClassPart::*)(TArgs...)>
{
  using result_t = TResult;
  using arguments_t = std::tuple<TArgs...>;
};

template <typename Tuple>
struct make_reference_tuple_impl;

template <typename... TArguments>
struct make_reference_tuple_impl<std::tuple<TArguments...>> {
  using type = std::tuple<std::reference_wrapper<std::remove_cv_t<std::remove_reference_t<TArguments>>>...>;
};

template<template<typename...> class TType, typename TSpec>
struct is_instantiation_of_impl : std::false_type {};

template<template<typename...> class TType, typename... TArgs>
struct is_instantiation_of_impl<TType, TType<TArgs...>> : std::true_type {};

} // impl

/// @brief Get tuple element type id by given index.
/// Type id is guaranteed to be unique for different types.
/// For tuples with size less than or equal 16 works as switch/case, else iterates tuple with step of size 16 until finds needed block of size less than 16 and do switch case.
template <typename Tuple>
std::size_t get_tuple_value_type_id(std::size_t index) {
  return impl::get_tuple_value_type_id_impl<std::tuple_size_v<std::remove_reference_t<Tuple>>>::
    template value<Tuple>(index);
}

/// @brief Get tuple element by reference by given index.
/// For tuples with size less than or equal 16 works as switch/case, else iterates tuple with step of size 16 until finds needed block of size less than 16 and do switch case.
template <typename Tuple>
std::any get_tuple_value(Tuple&& t, std::size_t index) {
  return impl::get_tuple_value_impl<std::tuple_size_v<std::remove_reference_t<Tuple>>>::
    value(std::forward<Tuple>(t), index);
}

/// @brief Transform type into tuple.
/// For std::tuple<TArgs...> it does nothing.
/// For void it is std::tuple<>.
/// For other types T it is std::tuple<T>.
template<typename TType>
using parse_tuple_t = typename impl::parse_tuple_impl<TType>::result_t;

/// @brief ???
template<typename TFunction>
using function_result_t = typename impl::function_signature_impl<TFunction>::result_t;

/// @brief ???
template<typename TFunction>
using function_arguments_t = typename impl::function_signature_impl<TFunction>::arguments_t;

/// @brief Transform tuple's arguments into reference wrapper.
/// Transform drops const, volatile and reference qualifiers.
/// Usage example:
/// @code
/// std::is_same_v<
///   nds::fun::make_reference_tuple_t<std::tuple<int, const float, std::string&>>,
///   std::tuple<std::reference_wrapper<int>, std::reference_wrapper<float>, std::reference_wrapper<std::string>>>
///   == true
/// @endcode
template<typename TTuple>
using make_reference_tuple_t = typename impl::make_reference_tuple_impl<TTuple>::type;

/// @brief Checks if TSpec is instantiation of TType.
/// Usage example:
/// @code
/// nds::fun::is_instantiation_of_v<std::tuple, std::tuple<int, const float, std::string&>> == true
/// @endcode
template<template<typename...> class TType, typename TSpec>
inline constexpr bool is_instantiation_of_v = impl::is_instantiation_of_impl<TType, TSpec>::value;

} // nds::fun
