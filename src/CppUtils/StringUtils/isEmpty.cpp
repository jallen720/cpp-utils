#include "CppUtils/StringUtils/isEmpty.hpp"

#include <cstring>

#include "CppUtils/Errors/Validators/validateNotNull.hpp"


namespace CppUtils
{


bool isEmpty(const char * cString)
{
    validateNotNull("cString", "isEmpty", cString);
    return strcmp(cString, "") == 0;
}


} // namespace CppUtils
