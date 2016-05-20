#include "JCore/Errors/Validators/validateNotNull.hpp"

#include "JCore/Errors/nullArgError.hpp"


using std::string;


namespace JCore {


void validateNotNull(const string & parameter, const string & function, const void * arg) {
    if (arg == nullptr) {
        nullArgError(parameter, function);
    }
}


} // namespace JCore
