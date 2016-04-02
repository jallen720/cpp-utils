#include "JCore/Exceptions/MessageBuilders/buildArgMessage.hpp"

using std::string;

namespace JCore {

string buildArgMessage(
    const string& parameter,
    const string& function,
    const string& argInfo,
    const string& argDescription)
{
    return "\n  " +
           argDescription + " passed to \"" +
           parameter + "\" parameter for " +
           function + "()" +
           argInfo;
}

} // namespace JCore
