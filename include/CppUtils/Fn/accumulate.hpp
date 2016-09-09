#pragma once


namespace CppUtils
{


template<typename T, typename Container, typename Accumulator>
T accumulate(const T & initialValue, const Container & container, const Accumulator & accumulator);


} // namespace CppUtils


#include "CppUtils/Fn/accumulate.ipp"
