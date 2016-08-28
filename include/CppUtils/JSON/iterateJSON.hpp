#pragma once


#include <string>

#include "CppUtils/JSON/JSON.hpp"


namespace CppUtils {


template<typename JSONDataCB>
void iterateJSON(const JSON & json, const JSONDataCB & jsonDataCB);


} // namespace CppUtils


#include "CppUtils/JSON/iterateJSON.ipp"
