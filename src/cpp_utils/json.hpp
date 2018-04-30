#pragma once

#include <string>
#include "cpp_utils/dependencies/json.hpp"

namespace Cpp_Utils
{

using JSON = nlohmann::json;

JSON read_json_file(const std::string & path);
bool contains_key(const JSON & json, const std::string & key);
std::string get_type_name(const JSON & json);
JSON merge(const JSON & a, const JSON & b);

} // namespace Cpp_Utils
