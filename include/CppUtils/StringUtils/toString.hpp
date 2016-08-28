#pragma once


#include <string>


namespace CppUtils {


template<typename T>
std::string toString(const T val);


template<>
std::string toString(const bool isTrue);


} // namespace CppUtils


#include "CppUtils/StringUtils/toString.ipp"
