#pragma once


#include <vector>


namespace JCore {


template<typename T>
void remove(std::vector<T>& vector, const T& element);


template<typename T, typename Predicate>
void remove(std::vector<T>& vector, const Predicate& predicate);


} // namespace JCore


#include "JCore/VectorUtils/remove.ipp"
