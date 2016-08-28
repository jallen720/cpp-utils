#include "CppUtils/Errors/Validators/validateNotEmpty.hpp"

#include "CppUtils/Errors/emptyStringArgError.hpp"
#include "CppUtils/StringUtils/isEmpty.hpp"


using std::string;


namespace CppUtils {


void validateNotEmpty(const string & parameterName, const string & functionName, const string & arg) {
    if (arg.empty()) {
        emptyStringArgError(parameterName, functionName);
    }
}


void validateNotEmpty(const string & parameterName, const string & functionName, const char * arg) {
    if (isEmpty(arg)) {
        emptyStringArgError(parameterName, functionName);
    }
}


} // namespace CppUtils
