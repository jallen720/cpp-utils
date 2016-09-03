#pragma once


#include <vector>


namespace CppUtils {


template<typename T, typename Callback>
void forEach(const std::vector<T> & vector, const Callback & callback);


} // namespace CppUtils


#include "CppUtils/VectorUtils/forEach.ipp"
