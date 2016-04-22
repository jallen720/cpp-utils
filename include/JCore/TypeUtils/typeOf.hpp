#pragma once


#include <typeindex>


namespace JCore {


template<typename T>
std::type_index typeOf();


template<typename Any>
std::type_index typeOf(const Any& value);


} // namespace JCore


#include "JCore/TypeUtils/typeOf.ipp"
