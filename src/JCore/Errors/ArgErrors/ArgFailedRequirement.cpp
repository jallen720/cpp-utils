#include "JCore/Errors/ArgErrors/ArgFailedRequirement.hpp"

#include "JCore/Errors/MessageBuilders/buildArgMessage.hpp"

using std::string;

namespace JCore {

ArgFailedRequirement::ArgFailedRequirement(
    const string& parameter,
    const string& function,
    const string& requirement)
    : Error(buildArgMessage(
        parameter,
        function,
        " failed requirement:\n    " + requirement
    )) {}

} // namespace JCore
