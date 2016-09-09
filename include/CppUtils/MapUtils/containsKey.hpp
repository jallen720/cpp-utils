#pragma once


#include <map>


namespace CppUtils {


template<typename T, typename _>
bool containsKey(const std::map<const T, _> & map, const T & key);

template<typename T, typename _>
bool containsKey(const std::map<T, _> & map, const T & key);


} // namespace CppUtils


#include "CppUtils/MapUtils/containsKey.ipp"
