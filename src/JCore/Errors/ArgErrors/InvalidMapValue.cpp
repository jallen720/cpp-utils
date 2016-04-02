#include "JCore/Errors/ArgErrors/InvalidMapValue.hpp"

#include "JCore/Errors/MessageBuilders/buildArgMessage.hpp"
#include "JCore/Errors/MessageBuilders/buildArgInfo.hpp"
#include "JCore/Errors/MessageBuilders/buildMustBe.hpp"

using std::string;
using std::vector;

namespace JCore {

static string buildMapValueMessage(
    const string& parameter,
    const string& function,
    const string& key,
    const string& mustBe)
{
    return buildArgMessage(
        parameter,
        function,
        buildArgInfo(mustBe),
        "map value for \"" + key + "\" key in argument"
    );
}

InvalidMapValue::InvalidMapValue(
    const string&         parameter,
    const string&         function,
    const string&         key,
    const vector<string>& validValues)
    : Error(buildMapValueMessage(
        parameter,
        function,
        key,
        buildMustBe(validValues)
    )) {}

} // namespace JCore
