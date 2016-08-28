#pragma once


#include <string>


namespace JCore {


void validateNotEmpty(
    const std::string & parameterName,
    const std::string & functionName,
    const std::string & arg);


void validateNotEmpty(
    const std::string & parameterName,
    const std::string & functionName,
    const char * arg);


} // namespace JCore
