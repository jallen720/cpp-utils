#pragma once

#include <string>

#include "JCore/Exceptions/Error.hpp"

namespace JCore {

class FileError : public Error {
public:
    FileError(
        const std::string& path,
        const std::string& function,
        const std::string& message);
};

} // namespace JCore
