#include "CppUtils/TestUtils/validResourcePath.hpp"

#include "CppUtils/FileUtils/directify.hpp"


using std::string;


namespace CppUtils
{


string validResourcePath(const string & subDirectory, const string & name)
{
    static const string VALID_RESOURCES_DIRECTORY = "tests/resources/valid/";

    return VALID_RESOURCES_DIRECTORY + directify(subDirectory) + name;
}


} // namespace CppUtils
