#pragma once


#include <typeindex>


namespace JCore {


template<typename T>
std::type_index typeOf();


} // namespace JCore


#include "JCore/TypeUtils/typeOf.ipp"
