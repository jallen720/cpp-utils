#pragma once

#include <typeindex>

namespace cpp_utils
{

using Type = std::type_index;

template<typename T>
Type type_of();

} // namespace cpp_utils

#include "cpp_utils/type.ipp"
