#include "JCore/Errors/emptyStringArgError.hpp"

#include <stdexcept>

#include "JCore/Errors/MessageBuilders/buildArgMessage.hpp"


using std::string;
using std::runtime_error;


namespace JCore {


void emptyStringArgError(const string & parameterName, const string & functionName) {
    throw runtime_error(buildArgMessage(
        parameterName,
        functionName,
        " cannot be empty",
        "string argument"));
}


} // namespace JCore
