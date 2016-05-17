#pragma once


#include <vector>

#include "JCore/Errors/Error.hpp"


namespace JCore {


class InvalidMapKey final : public Error {
public:
    InvalidMapKey(
        const std::string & parameter,
        const std::string & function,
        const std::vector<std::string> & validKeys);
};


} // namespace JCore
