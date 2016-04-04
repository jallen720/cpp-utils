#include "JCore/TestUtils/validResourcePath.hpp"

using std::string;

namespace JCore {

string validResourcePath(const string& subDirectory, const string& name) {
    static const string VALID_RESOURCES_DIRECTORY = "tests/resources/valid/";

    return VALID_RESOURCES_DIRECTORY + subDirectory + name;
}

} // namespace JCore
