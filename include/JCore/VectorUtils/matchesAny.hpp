#pragma once


#include <vector>


namespace JCore {


template<typename T, typename Predicate>
bool matchesAny(const std::vector<T>& vector, const Predicate& predicate);


} // namespace JCore


#include "JCore/VectorUtils/matchesAny.ipp"
