#pragma once


#include <string>


namespace JCore {


std::string buildArgMessage(
    const std::string & parameterName,
    const std::string & functionName,
    const std::string & argInfo,
    const std::string & argDescription = "argument");


} // namespace JCore
