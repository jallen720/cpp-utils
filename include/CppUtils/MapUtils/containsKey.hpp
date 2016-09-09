#pragma once


#include <map>


namespace CppUtils
{


template<typename Key, typename Value>
bool containsKey(const std::map<Key, Value> & map, const Key & key);


} // namespace CppUtils


#include "CppUtils/MapUtils/containsKey.ipp"
