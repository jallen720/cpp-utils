#include <stdexcept>
#include "cpp_utils/errors.hpp"

using std::string;
using std::runtime_error;

namespace cpp_utils
{

string build_arg_message(
    const string & parameter_name,
    const string & function_name,
    const string & arg_info,
    const string & arg_description = "argument")
{
    return "\n  " +
           arg_description + " passed to \"" +
           parameter_name + "\" parameter for " +
           function_name + "()" +
           arg_info;
}

static string build_file_message(const string & path, const string & function_name, const string & message)
{
    return "error in file at " + path + " accessed by " + function_name + "(): " + message;
}

void empty_string_arg_error(const string & parameter_name, const string & function_name)
{
    throw runtime_error(build_arg_message(
        parameter_name,
        function_name,
        " cannot be empty",
        "string argument"));
}

void null_arg_error(const string & parameter_name, const string & function_name)
{
    throw runtime_error(build_arg_message(
        parameter_name,
        function_name,
        " cannot be null"));
}

void file_error(const string & path, const string & function_name, const string & message)
{
    throw runtime_error(build_file_message(path, function_name, message));
}

} // namespace cpp_utils
