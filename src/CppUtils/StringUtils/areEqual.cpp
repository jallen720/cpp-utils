#include "CppUtils/StringUtils/areEqual.hpp"

#include <cstring>


using String = std::string;


namespace CppUtils {


bool areEqual(const String & string, const char * cString) {
    return strcmp(string.c_str(), cString) == 0;
}


bool areEqual(const char * cStringA, const char * cStringB) {
    return strcmp(cStringA, cStringB) == 0;
}


} // namespace CppUtils
