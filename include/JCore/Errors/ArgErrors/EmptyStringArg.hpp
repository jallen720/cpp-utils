#pragma once


#include "JCore/Errors/Error.hpp"


namespace JCore {


class EmptyStringArg final : public Error {
public:
    EmptyStringArg(const std::string & parameter, const std::string & function);
};


} // namespace JCore
