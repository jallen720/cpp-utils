#pragma once


#include <stdexcept>
#include <string>


namespace JCore {


class Error : public std::runtime_error {
public:
    explicit Error(const std::string& message);
};


} // namespace JCore
