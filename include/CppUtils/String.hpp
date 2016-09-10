#pragma once


#include <string>
#include <vector>


namespace CppUtils
{


bool areEqual(const std::string & string, const char * cString);
bool areEqual(const char * cStringA, const char * cStringB);
bool isEmpty(const char * cString);
std::vector<std::string> split(const std::string & string, const char delimiter);

template<typename T>
std::string toString(const T value);

template<>
std::string toString(const bool value);


} // namespace CppUtils


#include "CppUtils/String.ipp"
