#pragma once

#include <typeindex>

namespace Cpp_Utils
{

using Type = std::type_index;

template<typename T>
Type type_of();

} // namespace Cpp_Utils

#include "Cpp_Utils/Type.ipp"
