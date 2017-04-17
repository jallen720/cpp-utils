#pragma once


#include <string>


namespace Cpp_Utils
{


std::string directify(const std::string & directory);
std::string read_file(std::string path);
bool file_exists(const std::string & path);


} // namespace Cpp_Utils
