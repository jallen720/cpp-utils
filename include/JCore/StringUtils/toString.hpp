#pragma once

#include <string>

namespace JCore {

template<typename T>
std::string toString(const T val);

template<>
std::string toString(const bool isTrue);

} // namespace JCore

#include "JCore/StringUtils/toString.ipp"
