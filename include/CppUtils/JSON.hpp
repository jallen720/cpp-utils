#pragma once


#include <string>

#include "CppUtils/__internal__/json.hpp"


namespace CppUtils
{


using JSON = nlohmann::json;

JSON read_json_file(const std::string & path);


} // namespace CppUtils
