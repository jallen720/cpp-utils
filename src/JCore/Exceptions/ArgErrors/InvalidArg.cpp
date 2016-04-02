#include "JCore/Exceptions/ArgErrors/InvalidArg.hpp"

#include "JCore/Exceptions/MessageBuilders/buildArgMessage.hpp"
#include "JCore/Exceptions/MessageBuilders/buildArgInfo.hpp"
#include "JCore/Exceptions/MessageBuilders/buildMustBe.hpp"

using std::string;
using std::vector;

namespace JCore {

string buildInvalidArgMessage(
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
