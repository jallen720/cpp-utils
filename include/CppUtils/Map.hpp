#pragma once


#include <map>
#include <vector>


namespace CppUtils
{


template<typename Key, typename Value>
bool containsKey(const std::map<Key, Value> & map, const Key & key);

template<typename Key, typename Value>
std::vector<Value> getValues(const std::map<Key, Value> & map);

template<typename Key, typename Value>
std::vector<Value> getValues(const std::map<Key, const Value> & map);


} // namespace CppUtils


#include "CppUtils/Map.ipp"
