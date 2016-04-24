#include "JCore/Errors/FileError.hpp"


using std::string;


namespace JCore {


static string buildFileMessage(
    const string& path,
    const string& function,
    const string& message)
{
    return "file at \"" + path +
           "\" accessed by " + function +
           "(): " + message;
}


static string buildFileMessage(
    const string& type,
    const string& path,
    const string& function,
    const string& message)
{
    return type + " " + buildFileMessage(path, function, message);
}


FileError::FileError(
    const string& path,
    const string& function,
    const string& message)
    : Error(buildFileMessage(path, function, message))
{}


FileError::FileError(
    const string& type,
    const string& path,
    const string& function,
    const string& message)
    : Error(buildFileMessage(type, path, function, message))
{}


} // namespace JCore
