#pragma once

#include <string>

namespace Cpp_Utils
{

void validate_not_empty(const std::string & parameter_name, const std::string & function_name, const std::string & arg);
void validate_not_empty(const std::string & parameter_name, const std::string & function_name, const char * arg);
void validate_not_null(const std::string & parameter_name, const std::string & function_name, const void * arg);

} // namespace Cpp_Utils
