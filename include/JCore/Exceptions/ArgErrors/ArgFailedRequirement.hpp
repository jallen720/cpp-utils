#pragma once

#include "JCore/Exceptions/Error.hpp"

namespace JCore {

class ArgFailedRequirement : public Error {
public:
    ArgFailedRequirement(
        const std::string& parameter,
        const std::string& function,
        const std::string& requirement);
};

} // namespace JCore
