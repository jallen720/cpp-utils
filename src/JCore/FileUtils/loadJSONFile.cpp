#include "JCore/FileUtils/loadJSONFile.hpp"

#include <stdexcept>

#include "JCore/FileUtils/File.hpp"
#include "JCore/Errors/Validators/validateNotEmpty.hpp"
#include "JCore/Errors/FileError.hpp"


using std::string;
using std::invalid_argument;


namespace JCore {


JSON loadJSONFile(const string & path) {
    validateNotEmpty("path", "loadJSONFile", path);

    try {
        return JSON::parse(File(path).getContent());
    }
    catch (const invalid_argument & error) {
        throw FileError("JSON", path, "loadJSONFile", error.what());
    }
}


} // namespace JCore
