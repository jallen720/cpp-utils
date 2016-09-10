#pragma once


#include <typeindex>


namespace CppUtils
{


using Type = std::type_index;

template<typename T>
Type typeOf();


} // namespace CppUtils


#include "CppUtils/Type.ipp"
