#include "JCore/Exceptions/Validators/validateNotEmpty.hpp"

#include <cstring>

#include "JCore/Exceptions/ArgErrors/EmptyStringArg.hpp"

using std::string;

namespace JCore {

void validateNotEmpty(const string& parameter, const string& function, const string& arg) {
    if (arg.empty()) {
        throw EmptyStringArg(parameter, function);
    }
}

bool isEmpty(const char* arg) {
    return strcmp(arg, "") == 0;
}

void validateNotEmpty(const string& parameter, const string& function, const char* arg) {
    if (isEmpty(arg)) {
        throw EmptyStringArg(parameter, function);
    }
}

} // namespace JCore
