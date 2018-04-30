#pragma once

#include <string>
#include <vector>

namespace Cpp_Utils
{

bool are_equal(const std::string & string, const char * cString);
bool are_equal(const char * cStringA, const char * cStringB);
bool is_empty(const char * cString);
std::vector<std::string> split(const std::string & string, const char delimiter);

template<typename T>
std::string to_string(const T value);

template<>
std::string to_string(const bool value);

} // namespace Cpp_Utils

#include "Cpp_Utils/String.ipp"
