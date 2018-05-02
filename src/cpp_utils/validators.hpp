#pragma once

#include <string>

namespace cpp_utils
{

void validate_not_empty(const std::string & parameter_name, const std::string & function_name, const std::string & arg);
void validate_not_empty(const std::string & parameter_name, const std::string & function_name, const char * arg);
void validate_not_null(const std::string & parameter_name, const std::string & function_name, const void * arg);

} // namespace cpp_utils
