#include "CppUtils/TestUtils/invalidResourcePath.hpp"

#include "CppUtils/FileUtils/directify.hpp"


using std::string;


namespace CppUtils {


string invalidResourcePath(const string & subDirectory, const string & name) {
    static const string INVALID_RESOURCES_DIRECTORY = "tests/resources/invalid/";

    return INVALID_RESOURCES_DIRECTORY + directify(subDirectory) + name;
}


} // namespace CppUtils
