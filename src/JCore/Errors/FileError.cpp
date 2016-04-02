#include "JCore/Errors/FileError.hpp"

using std::string;

namespace JCore {

static string buildFileMessage(const string& path, const string& function, const string& message) {
    return "file at \"" + path +
           "\" accessed by " + function +
           "() " + message;
}

FileError::FileError(const string& path, const string& function, const string& message)
    : Error(buildFileMessage(path, function, message)) {}

} // namespace JCore
