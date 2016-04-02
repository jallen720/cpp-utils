#include "JCore/Exceptions/ArgErrors/InvalidArgProperty.hpp"

#include "JCore/Exceptions/MessageBuilders/buildArgMessage.hpp"
#include "JCore/Exceptions/MessageBuilders/buildArgInfo.hpp"
#include "JCore/Exceptions/MessageBuilders/buildMustBe.hpp"

using std::string;
using std::vector;

namespace JCore {

string buildArgPropertyMessage(
    const string& parameter,
    const string& function,
    const string& property,
    const string& mustBe)
{
    return buildArgMessage(
        parameter,
        function,
        buildArgInfo(mustBe),
        "property \"" + property + "\" of argument"
    );
}

InvalidArgProperty::InvalidArgProperty(
    const string& parameter,
    const string& function,
    const string& property,
    const string& validProperty)
    : Error(buildArgPropertyMessage(
        parameter,
        function,
        property,
        validProperty
    )) {}

InvalidArgProperty::InvalidArgProperty(
    const string&         parameter,
    const string&         function,
    const string&         property,
    const vector<string>& validProperties)
    : Error(buildArgPropertyMessage(
        parameter,
        function,
        property,
        buildMustBe(validProperties)
    )) {}

} // namespace JCore
