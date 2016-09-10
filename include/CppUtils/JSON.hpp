#pragma once


#include <string>

#include "CppUtils/JSON/private/json.hpp"


namespace CppUtils
{


using JSON = nlohmann::json;

JSON readJSONFile(const std::string & path);


} // namespace CppUtils
