#pragma once


#include <vector>


namespace CppUtils {


template<typename T, typename Function>
void forEach(const std::vector<T> & vector, const Function & function);


} // namespace CppUtils


#include "CppUtils/VectorUtils/forEach.ipp"
