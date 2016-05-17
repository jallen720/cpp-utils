#pragma once


namespace JCore {


template<typename T, typename Container, typename Accumulator>
T accumulate(const T & initialValue, const Container & container, const Accumulator & accumulator);


} // namespace JCore


#include "JCore/Fn/accumulate.ipp"
