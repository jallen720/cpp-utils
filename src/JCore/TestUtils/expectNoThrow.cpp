#include "JCore/TestUtils/expectNoThrow.hpp"

#include <iostream>
#include <exception>
#include <gtest/gtest.h>

using std::cerr;
using std::exception;
using std::function;

namespace JCore {

void expectNoThrow(const function<void()>& block) {
    try {
        block();
    }
    catch (const exception& error) {
        cerr << "std::exception thrown in test:\n  " << error.what() << "\n";
        FAIL();
    }
    catch (...) {
        cerr << "Unknown exception thrown in test!\n";
        FAIL();
    }
}

} // namespace JCore
