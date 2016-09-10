#include "CppUtils/Errors.hpp"

#include <stdexcept>


using std::string;
using std::runtime_error;


namespace CppUtils
{


string buildArgMessage(
    const string & parameterName,
    const string & functionName,
    const string & argInfo,
    const string & argDescription = "argument")
{
    return "\n  " +
           argDescription + " passed to \"" +
           parameterName + "\" parameterName for " +
           functionName + "()" +
           argInfo;
}


static string buildFileMessage(
    const string & path,
    const string & functionName,
    const string & message)
{
    return "error in file at " + path + " accessed by " + functionName + "(): " + message;
}


void emptyStringArgError(const string & parameterName, const string & functionName)
{
    throw runtime_error(buildArgMessage(
        parameterName,
        functionName,
        " cannot be empty",
        "string argument"));
}


void nullArgError(const string & parameterName, const string & functionName)
{
    throw runtime_error(buildArgMessage(
        parameterName,
        functionName,
        " cannot be null"));
}


void fileError(
    const string & path,
    const string & functionName,
    const string & message)
{
    throw runtime_error(buildFileMessage(path, functionName, message));
}


} // namespace CppUtils
