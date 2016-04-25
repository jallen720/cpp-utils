#pragma once


#include <gtest/gtest.h>

#include "JCore/Event/Event.hpp"
#include "JCore/TestUtils/Interfaces/ITestEventListener.hpp"


namespace JCore {


struct SubscriptionTest : testing::Test {
protected:
    Event<ITestEventListener, int> testEvent { &ITestEventListener::onEvent };
};


} // namespace JCore
