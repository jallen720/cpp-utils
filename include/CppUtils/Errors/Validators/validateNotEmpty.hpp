#pragma once


#include <string>


namespace CppUtils {


void validateNotEmpty(
    const std::string & parameterName,
    const std::string & functionName,
    const std::string & arg);

void validateNotEmpty(
    const std::string & parameterName,
    const std::string & functionName,
    const char * arg);


} // namespace CppUtils
