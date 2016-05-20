#pragma once


#include <string>


namespace JCore {


void fileError(
    const std::string & path,
    const std::string & function,
    const std::string & message);

void fileError(
    const std::string & type,
    const std::string & path,
    const std::string & function,
    const std::string & message);


} // namespace JCore
