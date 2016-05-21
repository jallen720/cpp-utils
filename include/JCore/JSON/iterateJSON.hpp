#pragma once


#include <string>
#include <functional>

#include "JCore/JSON/JSON.hpp"


namespace JCore {


using JSONDataCB = std::function<void(const std::string &, const JSON &)>;


void iterateJSON(const JSON & json, const JSONDataCB & jsonDataCB);


} // namespace JCore
