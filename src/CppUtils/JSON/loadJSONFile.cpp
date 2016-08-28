#include "CppUtils/JSON/loadJSONFile.hpp"

#include <stdexcept>

#include "CppUtils/FileUtils/File.hpp"
#include "CppUtils/Errors/Validators/validateNotEmpty.hpp"
#include "CppUtils/Errors/fileError.hpp"


using std::string;
using std::invalid_argument;


namespace CppUtils {


JSON loadJSONFile(const string & path) {
    validateNotEmpty("path", "loadJSONFile", path);
    JSON json;

    try {
        json = JSON::parse(File(path).getContent());
    }
    catch (const invalid_argument & error) {
        fileError(path, "loadJSONFile", error.what());
    }

    return json;
}


} // namespace CppUtils
