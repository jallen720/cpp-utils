#include "JCore/Errors/ArgErrors/InvalidMapKey.hpp"

#include "JCore/Errors/MessageBuilders/buildArgMessage.hpp"
#include "JCore/Errors/MessageBuilders/buildArgInfo.hpp"
#include "JCore/Errors/MessageBuilders/buildMustBe.hpp"


using std::string;
using std::vector;


namespace JCore {


static string buildMapKeyMessage(
    const string & parameter,
    const string & function,
    const string & mustBe)
{
    return buildArgMessage(
        parameter,
        function,
        buildArgInfo(mustBe),
        "map key in argument");
}


InvalidMapKey::InvalidMapKey(
    const string & parameter,
    const string & function,
    const vector<string> & validKeys)
    : Error(buildMapKeyMessage(
        parameter,
        function,
        buildMustBe(validKeys)))
{}


} // namespace JCore
