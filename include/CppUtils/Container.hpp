#pragma once


#include <vector>
#include <map>

#include "CppUtils/JSON.hpp"


namespace CppUtils
{


template<typename T, typename Callback>
void for_each(const std::vector<T> & vector, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(const std::map<const T, U> & map, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(const std::map<T, U> & map, const Callback & callback);

template<typename Callback>
void for_each(const JSON & json, const Callback & callback);


} // namespace CppUtils


#include "CppUtils/Container.ipp"
