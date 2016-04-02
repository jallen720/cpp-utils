#include "JCore/Errors/ArgErrors/InvalidArg.hpp"

#include "JCore/Errors/MessageBuilders/buildArgMessage.hpp"
#include "JCore/Errors/MessageBuilders/buildArgInfo.hpp"
#include "JCore/Errors/MessageBuilders/buildMustBe.hpp"

using std::string;
using std::vector;

namespace JCore {

static string buildInvalidArgMessage(
    const string& parameter,
    const string& function,
    const string& mustBe)
{
    return buildArgMessage(parameter, function, buildArgInfo(mustBe));
}

InvalidArg::InvalidArg(
    const string& parameter,
    const string& function,
    const string& validArgument)
    : Error(buildInvalidArgMessage(
        parameter,
        function,
        validArgument
    )) {}

InvalidArg::InvalidArg(
    const string&         parameter,
    const string&         function,
    const vector<string>& validArguments)
    : Error(buildInvalidArgMessage(
        parameter,
        function,
        buildMustBe(validArguments)
    )) {}

} // namespace JCore
