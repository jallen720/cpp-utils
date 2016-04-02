#include "JCore/Exceptions/Validators/validateNotNull.hpp"

#include "JCore/Exceptions/ArgErrors/NullArg.hpp"

using std::string;

namespace JCore {

void validateNotNull(const string& parameter, const string& function, const void* arg) {
    if (arg == nullptr) {
        throw NullArg(parameter, function);
    }
}

} // namespace JCore
