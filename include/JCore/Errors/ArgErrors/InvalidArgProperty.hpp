#pragma once


#include <vector>

#include "JCore/Errors/Error.hpp"


namespace JCore {


class InvalidArgProperty final : public Error {
public:
    InvalidArgProperty(
        const std::string & parameter,
        const std::string & function,
        const std::string & property,
        const std::string & validProperty);

    InvalidArgProperty(
        const std::string & parameter,
        const std::string & function,
        const std::string & property,
        const std::vector<std::string> & validProperties);
};


} // namespace JCore
