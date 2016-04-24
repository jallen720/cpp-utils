#pragma once


#include <gtest/gtest.h>

#include "JCore/Event/Event.hpp"
#include "JCore/TestUtils/Interfaces/ITestEventListener.hpp"


namespace JCore {


struct EventTest : testing::Test {
protected:
    Event<ITestEventListener, int> testEvent { &ITestEventListener::onEvent };
};


} // namespace JCore
