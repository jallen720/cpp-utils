#pragma once


#include <vector>


namespace JCore {


template<typename T>
void removeElement(const std::vector<T>& vector, const T& element);


} // namespace JCore


#include "JCore/VectorUtils/removeElement.ipp"
