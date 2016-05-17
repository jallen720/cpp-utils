#pragma once


#include "JCore/Errors/Error.hpp"


namespace JCore {


class ArgFailedRequirement final : public Error {
public:
    ArgFailedRequirement(
        const std::string & parameter,
        const std::string & function,
        const std::string & requirement);
};


} // namespace JCore
