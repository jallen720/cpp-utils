#pragma once


#include <vector>
#include <map>

#include "Cpp_Utils/JSON.hpp"


namespace Cpp_Utils
{


template<typename T, typename Callback>
void for_each(const std::vector<T> & vector, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(const std::map<const T, U> & map, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(const std::map<T, U> & map, const Callback & callback);

template<typename Callback>
void for_each(const JSON & json, const Callback & callback);


} // namespace Cpp_Utils


#include "Cpp_Utils/Container.ipp"
