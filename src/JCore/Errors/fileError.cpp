#include "JCore/Errors/fileError.hpp"

#include <stdexcept>


using std::string;
using std::runtime_error;


namespace JCore {


static string buildFileMessage(
    const string & path,
    const string & function,
    const string & message)
{
    return "error in file at " + path +
           " accessed by " + function +
           "(): " + message;
}


void fileError(
    const string & path,
    const string & function,
    const string & message)
{
    throw runtime_error(buildFileMessage(path, function, message));
}


} // namespace JCore
