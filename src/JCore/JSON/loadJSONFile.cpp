#include "JCore/JSON/loadJSONFile.hpp"

#include <stdexcept>

#include "JCore/FileUtils/File.hpp"
#include "JCore/Errors/Validators/validateNotEmpty.hpp"
#include "JCore/Errors/fileError.hpp"


using std::string;
using std::invalid_argument;


namespace JCore {


JSON loadJSONFile(const string & path) {
    validateNotEmpty("path", "loadJSONFile", path);
    JSON json;

    try {
        json = JSON::parse(File(path).getContent());
    }
    catch (const invalid_argument & error) {
        fileError("JSON", path, "loadJSONFile", error.what());
    }

    return json;
}


} // namespace JCore
