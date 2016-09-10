#include "CppUtils/Errors/Validators.hpp"

#include "CppUtils/Errors.hpp"
#include "CppUtils/String.hpp"


using std::string;


namespace CppUtils
{


void validateNotEmpty(const string & parameterName, const string & functionName, const string & arg)
{
    if (arg.empty())
    {
        emptyStringArgError(parameterName, functionName);
    }
}


void validateNotEmpty(const string & parameterName, const string & functionName, const char * arg)
{
    if (isEmpty(arg))
    {
        emptyStringArgError(parameterName, functionName);
    }
}


void validateNotNull(const string & parameterName, const string & functionName, const void * arg)
{
    if (arg == nullptr)
    {
        nullArgError(parameterName, functionName);
    }
}


} // namespace CppUtils
