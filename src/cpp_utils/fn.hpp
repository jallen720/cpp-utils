#pragma once

#include <vector>

namespace cpp_utils
{

template<typename T, typename Container, typename Accumulator>
T accumulate(const T & initial_value, const Container & container, const Accumulator & accumulator);

template<typename T, typename Container, typename Transformer>
std::vector<T> transform(const Container & container, const Transformer & transformer);

template<typename T, typename Predicate>
std::vector<T> filter(const std::vector<T> & vector, const Predicate & predicate);

} // namespace cpp_utils

#include "cpp_utils/fn.ipp"
