#include "CppUtils/JSON/readJSONFile.hpp"

#include <stdexcept>

#include "CppUtils/FileUtils/readFile.hpp"
#include "CppUtils/Errors/Validators/validateNotEmpty.hpp"
#include "CppUtils/Errors/fileError.hpp"


using std::string;
using std::invalid_argument;


namespace CppUtils {


JSON readJSONFile(const string & path) {
    validateNotEmpty("path", "readJSONFile", path);
    JSON json;

    try {
        json = JSON::parse(readFile(path));
    }
    catch (const invalid_argument & error) {
        fileError(path, "readJSONFile", error.what());
    }

    return json;
}


} // namespace CppUtils
