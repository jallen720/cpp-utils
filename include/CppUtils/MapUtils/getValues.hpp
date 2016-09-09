#pragma once


#include <vector>
#include <map>


namespace CppUtils
{


template<typename Key, typename Value>
std::vector<Value> getValues(const std::map<Key, Value> & map);

template<typename Key, typename Value>
std::vector<Value> getValues(const std::map<Key, const Value> & map);


} // namespace CppUtils


#include "CppUtils/MapUtils/getValues.ipp"
