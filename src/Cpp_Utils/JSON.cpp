#include "Cpp_Utils/JSON.hpp"

#include <stdexcept>

#include "Cpp_Utils/File.hpp"
#include "Cpp_Utils/Validators.hpp"
#include "Cpp_Utils/Errors.hpp"


using std::string;
using std::invalid_argument;


namespace Cpp_Utils
{


JSON read_json_file(const string & path)
{
    validate_not_empty("path", "read_json_file", path);
    JSON json;

    try
    {
        json = JSON::parse(read_file(path));
    }
    catch (const invalid_argument & error)
    {
        file_error(path, "read_json_file", error.what());
    }

    return json;
}


bool contains_key(const JSON & json, const string & key)
{
    return json.find(key) != json.end();
}


string get_type_name(const JSON & json)
{
    return json.is_null() ? "null" :
           json.is_boolean() ? "boolean" :
           json.is_number() ? "number" :
           json.is_string() ? "string" :
           json.is_array() ? "array" :
           json.is_object() ? "object" :
           json.is_discarded() ? "discarded" :
           "undefined";
}


} // namespace Cpp_Utils
