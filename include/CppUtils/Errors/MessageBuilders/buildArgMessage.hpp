#pragma once


#include <string>


namespace CppUtils
{


std::string buildArgMessage(
    const std::string & parameterName,
    const std::string & functionName,
    const std::string & argInfo,
    const std::string & argDescription = "argument");


} // namespace CppUtils
