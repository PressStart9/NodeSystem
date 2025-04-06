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