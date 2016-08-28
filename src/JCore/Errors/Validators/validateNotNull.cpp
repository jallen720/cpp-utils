#include "JCore/Errors/Validators/validateNotNull.hpp"

#include "JCore/Errors/nullArgError.hpp"


using std::string;


namespace JCore {


void validateNotNull(const string & parameterName, const string & functionName, const void * arg) {
    if (arg == nullptr) {
        nullArgError(parameterName, functionName);
    }
}


} // namespace JCore
