#pragma once

#include <vector>

namespace Cpp_Utils
{

template<typename T>
bool contains(const std::vector<T> & vector, const T & element);

template<typename T, typename Predicate>
bool contains(const std::vector<T> & vector, const Predicate & predicate);

template<typename T>
void remove(std::vector<T> & vector, const T & element);

template<typename T, typename Predicate>
void remove(std::vector<T> & vector, const Predicate & predicate);

template<typename T>
void remove_at_index(std::vector<T> & vector, const unsigned int index);

template<typename T, typename Comparator>
void sort(std::vector<T> & vector, const Comparator & comparator);

template<typename T>
void concat(std::vector<T> & to_vector, const std::vector<T> & from_vector);

} // namespace Cpp_Utils

#include "cpp_utils/vector.ipp"
