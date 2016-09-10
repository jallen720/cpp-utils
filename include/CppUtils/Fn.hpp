#pragma once


#include <vector>


namespace CppUtils
{


template<typename T, typename Container, typename Accumulator>
T accumulate(const T & initial_value, const Container & container, const Accumulator & accumulator);

template<typename T, typename Container, typename Function>
std::vector<T> transform(const Container & container, const Function & function);


} // namespace CppUtils


#include "CppUtils/Fn.ipp"
