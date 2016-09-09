#include "CppUtils/Errors/emptyStringArgError.hpp"

#include <stdexcept>

#include "CppUtils/Errors/MessageBuilders/buildArgMessage.hpp"


using std::string;
using std::runtime_error;


namespace CppUtils
{


void emptyStringArgError(const string & parameterName, const string & functionName)
{
    throw runtime_error(buildArgMessage(
        parameterName,
        functionName,
        " cannot be empty",
        "string argument"));
}


} // namespace CppUtils
