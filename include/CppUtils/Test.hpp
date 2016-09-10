#pragma once


#include <string>
#include <vector>
#include <functional>


namespace CppUtils
{


template<typename T>
void assertEqualElements(
    const std::vector<T> & expectedElements,
    const std::vector<T> & actualElements);

void assertNoThrow(const std::function<void()> & block);
std::string invalidResourcePath(const std::string & subDirectory, const std::string & name);
std::string validResourcePath(const std::string & subDirectory, const std::string & name);


} // namespace CppUtils


#include "CppUtils/Test.ipp"
