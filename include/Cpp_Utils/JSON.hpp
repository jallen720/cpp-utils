#pragma once


#include <string>

#include "Cpp_Utils/__internal__/json.hpp"


namespace Cpp_Utils
{


using JSON = nlohmann::json;

JSON read_json_file(const std::string & path);


} // namespace Cpp_Utils
