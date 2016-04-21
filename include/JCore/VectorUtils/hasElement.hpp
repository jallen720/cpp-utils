#pragma once


#include <vector>


namespace JCore {


template<typename T>
bool hasElement(const std::vector<T>& vector, const T& element);


} // namespace JCore


#include "JCore/VectorUtils/hasElement.ipp"
