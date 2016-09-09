#include "CppUtils/Errors/Validators/validateNotNull.hpp"

#include "CppUtils/Errors/nullArgError.hpp"


using std::string;


namespace CppUtils
{


void validateNotNull(const string & parameterName, const string & functionName, const void * arg)
{
    if (arg == nullptr)
    {
        nullArgError(parameterName, functionName);
    }
}


} // namespace CppUtils
