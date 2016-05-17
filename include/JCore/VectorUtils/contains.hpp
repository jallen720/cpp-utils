#pragma once


#include <vector>


namespace JCore {


template<typename T>
bool contains(const std::vector<T> & vector, const T & element);


template<typename T, typename Predicate>
bool contains(const std::vector<T> & vector, const Predicate & predicate);


} // namespace JCore


#include "JCore/VectorUtils/contains.ipp"
