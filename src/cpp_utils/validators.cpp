#include "cpp_utils/validators.hpp"
#include "cpp_utils/errors.hpp"
#include "cpp_utils/string.hpp"

using std::string;

namespace cpp_utils
{

void validate_not_empty(const string & parameter_name, const string & function_name, const string & arg)
{
    if (arg.empty())
    {
        empty_string_arg_error(parameter_name, function_name);
    }
}

void validate_not_empty(const string & parameter_name, const string & function_name, const char * arg)
{
    if (is_empty(arg))
    {
        empty_string_arg_error(parameter_name, function_name);
    }
}

void validate_not_null(const string & parameter_name, const string & function_name, const void * arg)
{
    if (arg == nullptr)
    {
        null_arg_error(parameter_name, function_name);
    }
}

} // namespace cpp_utils
