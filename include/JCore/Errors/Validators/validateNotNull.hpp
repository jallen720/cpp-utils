#pragma once


#include <string>


namespace JCore {


void validateNotNull(
    const std::string & parameterName,
    const std::string & functionName,
    const void * arg);


} // namespace JCore
