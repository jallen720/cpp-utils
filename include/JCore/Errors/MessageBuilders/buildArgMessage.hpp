#pragma once


#include <string>


namespace JCore {


std::string buildArgMessage(
    const std::string& parameter,
    const std::string& function,
    const std::string& argInfo,
    const std::string& argDescription = "argument");


} // namespace JCore
