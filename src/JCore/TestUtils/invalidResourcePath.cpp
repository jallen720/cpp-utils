#include "JCore/TestUtils/invalidResourcePath.hpp"

#include "JCore/FileUtils/directify.hpp"


using std::string;


namespace JCore {


string invalidResourcePath(const string& subDirectory, const string& name) {
    static const string INVALID_RESOURCES_DIRECTORY = "tests/resources/invalid/";

    return INVALID_RESOURCES_DIRECTORY + directify(subDirectory) + name;
}


} // namespace JCore
