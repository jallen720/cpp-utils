#include "JCore/Errors/Validators/validateNotNull.hpp"


namespace JCore {


template<typename Listener>
static Listener* getValidListener(Listener* listener) {
    validateNotNull("listener", "Subscription<>::Subscription", listener);
    return listener;
}


template<typename Listener, typename ...Args>
Subscription<Listener, Args...>::Subscription(SubscriptionEvent& event, Listener* listener)
    : m_event(event)
    , m_listener(getValidListener(listener))
{
    m_event.subscribe(m_listener);
}


template<typename Listener, typename ...Args>
Subscription<Listener, Args...>::~Subscription() {
    m_event.unsubscribe(m_listener);
}


} // namespace JCore
