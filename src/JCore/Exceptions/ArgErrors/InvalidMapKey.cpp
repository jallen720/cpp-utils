#include "JCore/Exceptions/ArgErrors/InvalidMapKey.hpp"

#include "JCore/Exceptions/MessageBuilders/buildArgMessage.hpp"
#include "JCore/Exceptions/MessageBuilders/buildArgInfo.hpp"
#include "JCore/Exceptions/MessageBuilders/buildMustBe.hpp"

using std::string;
using std::vector;

namespace JCore {

string buildMapKeyMessage(
    const string& parameter,
    const string& function,
    const string& mustBe)
{
    return buildArgMessage(
        parameter,
        function,
        buildArgInfo(mustBe),
        "map key in argument"
    );
}

InvalidMapKey::InvalidMapKey(
    const string&         parameter,
    const string&         function,
    const vector<string>& validKeys)
    : Error(buildMapKeyMessage(
        parameter,
        function,
        buildMustBe(validKeys)
    )) {}

} // namespace JCore
