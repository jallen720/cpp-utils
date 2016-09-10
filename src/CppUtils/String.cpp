#include "CppUtils/String.hpp"

#include <cstring>
#include <sstream>

#include "CppUtils/Validators.hpp"


using std::vector;
using std::stringstream;
using std::getline;


namespace CppUtils
{


bool areEqual(const std::string & string, const char * cString)
{
    return strcmp(string.c_str(), cString) == 0;
}


bool areEqual(const char * cStringA, const char * cStringB)
{
    return strcmp(cStringA, cStringB) == 0;
}


bool isEmpty(const char * cString)
{
    validateNotNull("cString", "isEmpty", cString);
    return strcmp(cString, "") == 0;
}


vector<std::string> split(const std::string & string, const char delimiter)
{
    vector<std::string> elements;
    stringstream stream(string);
    std::string element;

    while (getline(stream, element, delimiter))
    {
        elements.push_back(element);
    }

    return elements;
}


template<>
std::string toString(const bool value)
{
    return value == true ? "true" : "false";
}


} // namespace CppUtils
