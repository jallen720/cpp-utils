#pragma once


#include <functional>


namespace JCore {


void assertNoThrow(const std::function<void()> & block);


} // namespace JCore
