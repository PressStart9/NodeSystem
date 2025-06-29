#pragma once

#include <tuple>

namespace nds::fun {

namespace impl {

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

template<typename TResult, typename... TArgs>
struct function_signature_impl<TResult(TArgs...)>
{
  using result_t = TResult;
  using arguments_t = std::tuple<TArgs...>;
};

template <typename Argument>
struct ref_or_left_impl {
  using type = Argument;
};

template <typename Argument>
struct ref_or_left_impl<Argument&> {
  using type = std::reference_wrapper<Argument>;
};

template <typename Tuple>
struct make_reference_tuple_impl;

template <typename... TArguments>
struct make_reference_tuple_impl<std::tuple<TArguments...>> {
  using type = std::tuple<typename ref_or_left_impl<TArguments>::type...>;
};

template<template<typename...> class TType, typename TSpec>
struct is_instantiation_of_impl : std::false_type {};

template<template<typename...> class TType, typename... TArgs>
struct is_instantiation_of_impl<TType, TType<TArgs...>> : std::true_type {};

template<typename TFunctor>
struct callable_functor_impl;

template<typename TResult, typename TClassPart, typename... TArgs>
struct callable_functor_impl<TResult(TClassPart::*)(TArgs...)> {
  using type = TResult(TArgs...);
};

template<typename TResult, typename TClassPart, typename... TArgs>
struct callable_functor_impl<TResult(TClassPart::*)(TArgs...) const> {
  using type = TResult(TArgs...);
};

template<typename TCallable>
struct callable_func_impl;

template<typename TCallable>
struct callable_func_impl {
  using type = typename callable_functor_impl<decltype(std::decay_t<TCallable>::operator())>::type;
};

template<typename TResult, typename... TArgs>
struct callable_func_impl<TResult(*)(TArgs...)> {
  using type = TResult(TArgs...);
};

template<typename TResult, typename... TArgs>
struct callable_func_impl<TResult(TArgs...)> {
  using type = TResult(TArgs...);
};

template<typename T>
struct is_integral_constant_impl : std::false_type {};

template<typename T, T Value>
struct is_integral_constant_impl<std::integral_constant<T, Value>> : std::true_type {};

template<typename T>
struct parse_size_impl {
  using callable_t = typename callable_func_impl<T>::type;
  using arguments_t = typename function_signature_impl<callable_t>::arguments_t;
  static constexpr size_t value = []() constexpr {
    if constexpr (std::tuple_size_v<arguments_t> != 0) {
      if constexpr (is_integral_constant_impl<std::tuple_element_t<std::tuple_size_v<arguments_t> - 1, arguments_t>>{}) {
        return std::tuple_element_t<std::tuple_size_v<arguments_t> - 1, arguments_t>::value;
      } else {
        return T::size;
      }
    } else {
      return T::size;
    }
  }();
};

} // impl

/// @brief Transform type into tuple.
/// For `std::tuple<TArgs...>` it does nothing.
/// For `void` it is std::tuple<>.
/// For other types `T` it is `std::tuple<T>`.
template<typename TType>
using parse_tuple_t = typename impl::parse_tuple_impl<TType>::result_t;

/// @brief Parse size from functor `static constexpr size_t size` or from `std::integral_constant` from function signature (as last argument).
template<typename TType>
static constexpr size_t parse_size_v = impl::parse_size_impl<TType>::value;

/// @brief Type of member function result.
template<typename TFunction>
using function_result_t = typename impl::function_signature_impl<TFunction>::result_t;

/// @brief Type of member function arguments as `std::tuple`.
template<typename TFunction>
using function_arguments_t = typename impl::function_signature_impl<TFunction>::arguments_t;

/// @brief Transforms references to `std::reference_wrapper`.
template<typename TArgument>
using ref_or_left_t = typename impl::ref_or_left_impl<TArgument>::type;

/// @brief Transform tuple's arguments with reference into reference wrapper.
/// Usage example:
/// @code
/// std::is_same_v<
///   nds::fun::make_reference_tuple_t<std::tuple<int, const float&, std::string&>>,
///   std::tuple<int, std::reference_wrapper<const float>, std::reference_wrapper<std::string>>>
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

template<typename TCallable>
using callable_func_t = typename impl::callable_func_impl<TCallable>::type;

} // nds::fun