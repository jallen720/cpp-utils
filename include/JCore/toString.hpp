#pragma once

#include <string>

namespace JCore {

template<typename T>
const std::string toString(T val) {
    return std::to_string(val);
}

template<>
const std::string toString(bool val);

} // namespace JCore
