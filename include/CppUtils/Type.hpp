#pragma once


#include <typeindex>


namespace CppUtils
{


using Type = std::type_index;

template<typename T>
Type type_of();


} // namespace CppUtils


#include "CppUtils/Type.ipp"
