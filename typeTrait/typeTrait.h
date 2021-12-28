#ifndef __TYPE_TRAIT_H__
#define __TYPE_TRAIT_H__

namespace {
    template <typename T> constexpr bool is_const_base          = false;
    template <typename T> constexpr bool is_const_base<T const> = true;

    template <typename T> constexpr bool is_pointer_base     = false;
    template <typename T> constexpr bool is_pointer_base<T*> = true;
}

template <typename T> struct remove_reference      { using type = T; };
template <typename T> struct remove_reference<T&>  { using type = T; };
template <typename T> struct remove_reference<T&&> { using type = T; };

template <typename T> struct remove_const          { using type = T; };
template <typename T> struct remove_const<T const> { using type = T; };

template <typename T> constexpr bool is_lValueReference      = false;
template <typename T> constexpr bool is_rValueReference      = false;
template <typename T> constexpr bool is_lValueReference<T&>  = true;
template <typename T> constexpr bool is_rValueReference<T&&> = true;

template <typename T> constexpr bool is_reference = is_lValueReference<T> || is_rValueReference<T>;
template <typename T> constexpr bool is_pointer   = is_pointer_base<typename remove_const<T>::type>;
template <typename T> constexpr bool is_const     = is_const_base<typename remove_reference<T>::type>;

template <typename T, unsigned long long N = 0> constexpr bool is_array       = false;
template <typename T, unsigned long long N>     constexpr bool is_array<T[N]> = true;
template <typename T>                           constexpr bool is_array<T[]>  = true;

#endif