#include "JCore/Event/Subscription.hpp"

#include <stdexcept>

#include "JCore/Event/Fixtures/SubscriptionTest.hpp"


using std::runtime_error;


namespace JCore {


TEST_F(SubscriptionTest, subscription) {
    ITestEventListener testEventListener;
    Subscription<ITestEventListener, int> subscription(testEvent, &testEventListener);

    ASSERT_TRUE(testEvent.isSubscribed(&testEventListener));
}


TEST_F(SubscriptionTest, subscriptionForNullListener) {
    const auto runTest = [&]() -> void {
        Subscription<ITestEventListener, int>(testEvent, nullptr);
    };

    ASSERT_THROW(runTest(), runtime_error);
}


TEST_F(SubscriptionTest, unsubscribesWhenDestroyed) {
    ITestEventListener testEventListener;

    {
        Subscription<ITestEventListener, int> subscription(testEvent, &testEventListener);
    }

    ASSERT_FALSE(testEvent.isSubscribed(&testEventListener));
}


} // namespace JCore
