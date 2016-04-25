#include <stdexcept>

#include "JCore/Event/Fixtures/EventTest.hpp"
#include "JCore/TestUtils/assertNoThrow.hpp"
#include "JCore/Errors/ArgErrors/NullArg.hpp"


using std::runtime_error;


namespace JCore {


TEST_F(EventTest, subscribe) {
    ITestEventListener testEventListener;

    assertNoThrow([&]() {
        testEvent.subscribe(&testEventListener);
    });
}


TEST_F(EventTest, subscribeNullListener) {
    ASSERT_THROW(testEvent.subscribe(nullptr), NullArg);
}


TEST_F(EventTest, subscribeDuplicateListener) {
    ITestEventListener testEventListener;
    testEvent.subscribe(&testEventListener);

    ASSERT_THROW(testEvent.subscribe(&testEventListener), runtime_error);
}


TEST_F(EventTest, unsubscribe) {
    ITestEventListener testEventListener;
    testEvent.subscribe(&testEventListener);

    assertNoThrow([&]() {
        testEvent.unsubscribe(&testEventListener);
    });
}


TEST_F(EventTest, unsubscribeNullListener) {
    ASSERT_THROW(testEvent.unsubscribe(nullptr), NullArg);
}


TEST_F(EventTest, unsubscribeNonSubscribedListener) {
    ITestEventListener testEventListener;

    ASSERT_THROW(testEvent.unsubscribe(&testEventListener), runtime_error);
}


TEST_F(EventTest, trigger) {
    struct TestEventListener final : ITestEventListener {
        int value = 0;

        // ITestEventListener
        virtual void onEvent(int value) override {
            this->value = value;
        }
    } testEventListener;

    const auto expectedValue = 12;
    testEvent.subscribe(&testEventListener);
    testEvent.trigger(expectedValue);

    ASSERT_EQ(expectedValue, testEventListener.value);
}


} // namespace JCore
