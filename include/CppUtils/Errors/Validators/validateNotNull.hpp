#pragma once


#include <string>


namespace CppUtils {


void validateNotNull(
    const std::string & parameterName,
    const std::string & functionName,
    const void * arg);


} // namespace CppUtils
