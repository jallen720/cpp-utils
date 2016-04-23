#pragma once


#include <map>


namespace JCore {


template<typename T, typename _>
const bool containsKey(const std::map<const T, _>& map, const T& key);


template<typename T, typename _>
const bool containsKey(const std::map<T, _>& map, const T& key);


} // namespace JCore


#include "JCore/MapUtils/containsKey.ipp"
