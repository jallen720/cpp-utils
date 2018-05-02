#pragma once

#include <string>

namespace cpp_utils
{

std::string directify(const std::string & directory);
std::string platform_path(std::string path);
std::string read_file(std::string path);
bool file_exists(const std::string & path);

} // namespace cpp_utils
