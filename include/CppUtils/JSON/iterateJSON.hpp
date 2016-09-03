#pragma once


#include <string>

#include "CppUtils/JSON/JSON.hpp"


namespace CppUtils {


template<typename Callback>
void iterateJSON(const JSON & json, const Callback & callback);


} // namespace CppUtils


#include "CppUtils/JSON/iterateJSON.ipp"
