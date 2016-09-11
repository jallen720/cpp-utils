#pragma once


#include <vector>


namespace Cpp_Utils
{


template<typename T, typename Container, typename Accumulator>
T accumulate(const T & initial_value, const Container & container, const Accumulator & accumulator);

template<typename T, typename Container, typename Transformer>
std::vector<T> transform(const Container & container, const Transformer & transformer);


} // namespace Cpp_Utils


#include "Cpp_Utils/Fn.ipp"