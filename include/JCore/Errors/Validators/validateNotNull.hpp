#pragma once


#include <string>


namespace JCore {


void validateNotNull(
    const std::string& parameter,
    const std::string& function,
    const void*        arg);


} // namespace JCore
