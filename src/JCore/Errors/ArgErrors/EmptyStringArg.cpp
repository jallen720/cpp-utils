#include "JCore/Errors/ArgErrors/EmptyStringArg.hpp"

#include "JCore/Errors/MessageBuilders/buildArgMessage.hpp"

using std::string;

namespace JCore {

EmptyStringArg::EmptyStringArg(const string& parameter, const string& function)
    : Error(buildArgMessage(
        parameter,
        function,
        " cannot be empty",
        "string argument"
    )) {}

} // namespace JCore
