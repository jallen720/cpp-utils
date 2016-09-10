#pragma once


#include <string>


namespace CppUtils
{


void emptyStringArgError(const std::string & parameterName, const std::string & functionName);
void nullArgError(const std::string & parameterName, const std::string & functionName);

void fileError(
    const std::string & path,
    const std::string & functionName,
    const std::string & message);


} // namespace CppUtils
