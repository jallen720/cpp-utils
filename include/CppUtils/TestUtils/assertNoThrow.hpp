#pragma once


#include <functional>


namespace CppUtils
{


void assertNoThrow(const std::function<void()> & block);


} // namespace CppUtils
