#include "CppUtils/JSON.hpp"

#include <stdexcept>

#include "CppUtils/File.hpp"
#include "CppUtils/Validators.hpp"
#include "CppUtils/Errors.hpp"


using std::string;
using std::invalid_argument;


namespace CppUtils
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


} // namespace CppUtils
