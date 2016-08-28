#include "JCore/Errors/Validators/validateNotEmpty.hpp"

#include "JCore/Errors/emptyStringArgError.hpp"
#include "JCore/StringUtils/isEmpty.hpp"


using std::string;


namespace JCore {


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


} // namespace JCore
