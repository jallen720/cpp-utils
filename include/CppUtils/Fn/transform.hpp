#pragma once


#include <vector>


namespace CppUtils
{


template<typename T, typename Container, typename Function>
std::vector<T> transform(const Container & container, const Function & function);


} // namespace CppUtils


#include "CppUtils/Fn/transform.ipp"
