#pragma once

#include "JCore/Exceptions/Error.hpp"

namespace JCore {

class NullArg : public Error {
public:
    NullArg(const std::string& parameter, const std::string& function);
};

} // namespace JCore
