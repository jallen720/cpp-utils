#include <vector>
#include <stdexcept>
#include "Cpp_Utils/JSON.hpp"
#include "Cpp_Utils/File.hpp"
#include "Cpp_Utils/Validators.hpp"
#include "Cpp_Utils/Errors.hpp"
#include "Cpp_Utils/Collection.hpp"
#include "Cpp_Utils/Vector.hpp"

using std::string;
using std::vector;
using std::invalid_argument;
using std::runtime_error;

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

JSON merge(const JSON & a, const JSON & b)
{
    JSON merged = a;

    if ((a.is_object() || a.is_null()) && b.is_object())
    {
        for_each(b, [&](const string & key, const JSON & value) -> void
        {
            if (!contains_key(merged, key))
            {
                merged[key] = value;
            }
            else
            {
                JSON & merged_field = merged[key];

                if (merged_field.type() != value.type())
                {
                    throw runtime_error("ERROR: mismatched types for key \"" + key + "\" when merging JSON!");
                }
                // object
                else if (value.is_object())
                {
                    merged_field = merge(merged_field, value);
                }
                // array
                else if (value.is_array())
                {
                    vector<JSON> merged_array = merged_field;

                    for (const JSON & element : value)
                    {
                        // TODO: remove if nothing needs it?
                        if (!contains(merged_array, element))
                        {
                            merged_array.push_back(element);
                        }
                    }

                    merged_field = merged_array;
                }
                // boolean / number / string / null
                else
                {
                    merged_field = value;
                }
            }
        });
    }

    return merged;
}

} // namespace Cpp_Utils
