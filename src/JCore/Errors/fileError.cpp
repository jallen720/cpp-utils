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
    return "file at \"" + path +
           "\" accessed by " + function +
           "(): " + message;
}


static string buildFileMessage(
    const string & type,
    const string & path,
    const string & function,
    const string & message)
{
    return type + " " + buildFileMessage(path, function, message);
}


void fileError(
    const string & path,
    const string & function,
    const string & message)
{
    throw runtime_error(buildFileMessage(path, function, message));
}


void fileError(
    const string & type,
    const string & path,
    const string & function,
    const string & message)
{
    throw runtime_error(buildFileMessage(type, path, function, message));
}


} // namespace JCore
