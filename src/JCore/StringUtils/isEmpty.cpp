#include "JCore/StringUtils/isEmpty.hpp"

#include <cstring>

#include "JCore/Errors/Validators/validateNotNull.hpp"


namespace JCore {


bool isEmpty(const char * cString) {
    validateNotNull("cString", "isEmpty", cString);
    return strcmp(cString, "") == 0;
}


} // namespace JCore
