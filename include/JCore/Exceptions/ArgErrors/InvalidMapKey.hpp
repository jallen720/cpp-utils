#pragma once

#include <vector>

#include "JCore/Exceptions/Error.hpp"

namespace JCore {

class InvalidMapKey : public Error {
public:
    InvalidMapKey(
        const std::string&              parameter,
        const std::string&              function,
        const std::vector<std::string>& validKeys);
};

} // namespace JCore
