#include "JCore/Errors/Validators/validateNotEmpty.hpp"

#include "JCore/Errors/emptyStringArgError.hpp"
#include "JCore/StringUtils/isEmpty.hpp"


using std::string;


namespace JCore {


void validateNotEmpty(const string & parameter, const string & function, const string & arg) {
    if (arg.empty()) {
        emptyStringArgError(parameter, function);
    }
}


void validateNotEmpty(const string & parameter, const string & function, const char * arg) {
    if (isEmpty(arg)) {
        emptyStringArgError(parameter, function);
    }
}


} // namespace JCore
