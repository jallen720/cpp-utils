#pragma once


#include <string>

#include "Cpp_Utils/__internal__/json.hpp"


namespace Cpp_Utils
{


using JSON = nlohmann::json;

JSON read_json_file(const std::string & path);
bool contains_key(const JSON & json, const std::string & key);


} // namespace Cpp_Utils
