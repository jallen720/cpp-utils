#pragma once


#include "JCore/Errors/Error.hpp"


namespace JCore {


class NullArg : public Error {
public:
    NullArg(const std::string& parameter, const std::string& function);
};


} // namespace JCore
