#pragma once


#include <string>


namespace Cpp_Utils
{


void empty_string_arg_error(const std::string & parameter_name, const std::string & function_name);
void null_arg_error(const std::string & parameter_name, const std::string & function_name);
void file_error(const std::string & path, const std::string & function_name, const std::string & message);


} // namespace Cpp_Utils
