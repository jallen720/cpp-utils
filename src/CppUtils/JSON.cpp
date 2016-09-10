#include "CppUtils/JSON.hpp"

#include <stdexcept>

#include "CppUtils/File.hpp"
#include "CppUtils/Validators.hpp"
#include "CppUtils/Errors.hpp"


using std::string;
using std::invalid_argument;


namespace CppUtils
{


JSON readJSONFile(const string & path)
{
    validateNotEmpty("path", "readJSONFile", path);
    JSON json;

    try
    {
        json = JSON::parse(readFile(path));
    }
    catch (const invalid_argument & error)
    {
        fileError(path, "readJSONFile", error.what());
    }

    return json;
}


} // namespace CppUtils
