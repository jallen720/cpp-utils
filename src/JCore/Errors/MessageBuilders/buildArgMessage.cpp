#include "JCore/Errors/MessageBuilders/buildArgMessage.hpp"


using std::string;


namespace JCore {


string buildArgMessage(
    const string & parameterName,
    const string & functionName,
    const string & argInfo,
    const string & argDescription)
{
    return "\n  " +
           argDescription + " passed to \"" +
           parameterName + "\" parameterName for " +
           functionName + "()" +
           argInfo;
}


} // namespace JCore
