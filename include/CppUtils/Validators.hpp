#pragma once


#include <string>


namespace CppUtils
{


void validate_not_empty(const std::string & parameter_name, const std::string & function_name, const std::string & arg);
void validate_not_empty(const std::string & parameter_name, const std::string & function_name, const char * arg);
void validate_not_null(const std::string & parameter_name, const std::string & function_name, const void * arg);


} // namespace CppUtils
