#pragma once


#include <string>

#include "JCore/JSON/JSON.hpp"


namespace JCore {


template<typename JSONDataCB>
void iterateJSON(const JSON & json, const JSONDataCB & jsonDataCB);


} // namespace JCore


#include "JCore/JSON/iterateJSON.ipp"
