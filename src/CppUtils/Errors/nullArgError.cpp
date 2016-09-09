#include "CppUtils/Errors/nullArgError.hpp"

#include <stdexcept>

#include "CppUtils/Errors/MessageBuilders/buildArgMessage.hpp"


using std::string;
using std::runtime_error;


namespace CppUtils
{


void nullArgError(const string & parameterName, const string & functionName)
{
    throw runtime_error(buildArgMessage(
        parameterName,
        functionName,
        " cannot be null"));
}


} // namespace CppUtils
