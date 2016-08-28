#include "CppUtils/Errors/fileError.hpp"

#include <stdexcept>


using std::string;
using std::runtime_error;


namespace CppUtils {


static string buildFileMessage(
    const string & path,
    const string & functionName,
    const string & message)
{
    return "error in file at " + path +
           " accessed by " + functionName +
           "(): " + message;
}


void fileError(
    const string & path,
    const string & functionName,
    const string & message)
{
    throw runtime_error(buildFileMessage(path, functionName, message));
}


} // namespace CppUtils
