#include "JCore/Errors/Validators/validateNotEmpty.hpp"

#include "JCore/Errors/ArgErrors/EmptyStringArg.hpp"
#include "JCore/StringUtils/isEmpty.hpp"


using std::string;


namespace JCore {


void validateNotEmpty(const string & parameter, const string & function, const string & arg) {
    if (arg.empty()) {
        throw EmptyStringArg(parameter, function);
    }
}


void validateNotEmpty(const string & parameter, const string & function, const char * arg) {
    if (isEmpty(arg)) {
        throw EmptyStringArg(parameter, function);
    }
}


} // namespace JCore
