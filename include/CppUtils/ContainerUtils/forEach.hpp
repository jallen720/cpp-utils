#pragma once


#include <vector>
#include <map>

#include "CppUtils/JSON/JSON.hpp"


namespace CppUtils {


template<typename T, typename Callback>
void forEach(const std::vector<T> & vector, const Callback & callback);


template<typename T, typename U, typename Callback>
void forEach(const std::map<const T, U> & map, const Callback & callback);


template<typename T, typename U, typename Callback>
void forEach(const std::map<T, U> & map, const Callback & callback);


template<typename Callback>
void forEach(const JSON & json, const Callback & callback);


} // namespace CppUtils


#include "CppUtils/ContainerUtils/forEach.ipp"
