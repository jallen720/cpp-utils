#pragma once


#include <string>

#include "JCore/Errors/Error.hpp"


namespace JCore {


class FileError : public Error {
public:
    FileError(
        const std::string& path,
        const std::string& function,
        const std::string& message);

    FileError(
        const std::string& type,
        const std::string& path,
        const std::string& function,
        const std::string& message);
};


} // namespace JCore
