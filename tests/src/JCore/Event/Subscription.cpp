#include "JCore/Event/Subscription.hpp"

#include "JCore/Event/Fixtures/SubscriptionTest.hpp"
#include "JCore/Errors/ArgErrors/NullArg.hpp"


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

    ASSERT_THROW(runTest(), NullArg);
}


TEST_F(SubscriptionTest, unsubscribesWhenDestroyed) {
    ITestEventListener testEventListener;

    {
        Subscription<ITestEventListener, int> subscription(testEvent, &testEventListener);
    }

    ASSERT_FALSE(testEvent.isSubscribed(&testEventListener));
}


} // namespace JCore
