#pragma once


#include <vector>


namespace CppUtils {


template<typename T>
void remove(std::vector<T> & vector, const T & element);


template<typename T, typename Predicate>
void remove(std::vector<T> & vector, const Predicate & predicate);


} // namespace CppUtils


#include "CppUtils/VectorUtils/remove.ipp"
