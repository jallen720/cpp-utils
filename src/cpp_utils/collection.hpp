#pragma once

#include <vector>
#include <map>
#include <unordered_map>
#include "yaml-cpp/yaml.h"
#include "cpp_utils/json.hpp"

namespace cpp_utils
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// for_each(std::vector<T>, Callback) overloads
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T, typename Callback>
void for_each(const std::vector<T> & vector, const Callback & callback);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// for_each(std::map<T, U>, Callback) overloads
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T, typename U, typename Callback>
void for_each(const std::map<const T, U> & map, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(const std::map<T, U> & map, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(std::map<const T, U> & map, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(std::map<T, U> & map, const Callback & callback);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// for_each(std::map<T, U>, std::map<T, U>::iterator, Callback) overloads
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T, typename U, typename Callback>
void for_each(
    const std::map<const T, U> & map,
    typename std::map<const T, U>::const_iterator begin,
    const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(const std::map<T, U> & map, typename std::map<T, U>::const_iterator begin, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(std::map<const T, U> & map, typename std::map<const T, U>::iterator begin, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(std::map<T, U> & map, typename std::map<T, U>::iterator begin, const Callback & callback);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// for_each(std::unordered_map<T, U>, Callback) overloads
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T, typename U, typename Callback>
void for_each(const std::unordered_map<const T, U> & map, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(const std::unordered_map<T, U> & map, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(std::unordered_map<const T, U> & map, const Callback & callback);

template<typename T, typename U, typename Callback>
void for_each(std::unordered_map<T, U> & map, const Callback & callback);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// for_each(JSON, Callback) overloads
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename Callback>
void for_each(const JSON & json, const Callback & callback);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// for_each(YAML::Node, Callback) overloads
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename Callback>
void for_each(const YAML::Node & yaml, const Callback & callback);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// find(T, std::vector<T>, Predicate) overloads
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T, typename Predicate>
bool find(T & out, const std::vector<T> & vector, const Predicate & predicate);


} // namespace cpp_utils

#include "cpp_utils/collection.ipp"
