#pragma once


#include <vector>


namespace JCore {


template<typename T>
void remove(const std::vector<T>& vector, const T& element);


} // namespace JCore


#include "JCore/VectorUtils/remove.ipp"
