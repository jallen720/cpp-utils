#pragma once

#include <vector>

#include "JCore/Exceptions/Error.hpp"

namespace JCore {

class InvalidMapValue : public Error {
public:
    InvalidMapValue(
        const std::string&              parameter,
        const std::string&              function,
        const std::string&              key,
        const std::vector<std::string>& validValues);
};

} // namespace JCore
