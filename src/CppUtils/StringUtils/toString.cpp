#include "CppUtils/StringUtils/toString.hpp"


using std::string;


namespace CppUtils
{


template<>
string toString(const bool isTrue)
{
    return isTrue ? "true" : "false";
}


} // namespace CppUtils
