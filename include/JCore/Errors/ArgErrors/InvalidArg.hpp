#pragma once

#include <vector>

#include "JCore/Errors/Error.hpp"

namespace JCore {

class InvalidArg : public Error {
public:
    InvalidArg(
        const std::string& parameter,
        const std::string& function,
        const std::string& validArgument);

    InvalidArg(
        const std::string&              parameter,
        const std::string&              function,
        const std::vector<std::string>& validArguments);
};

} // namespace JCore
