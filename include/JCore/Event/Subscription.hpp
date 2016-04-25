#pragma once


#include "JCore/Event/Event.hpp"


namespace JCore {


template<typename Listener, typename ...Args>
class Subscription final {
private:
    using SubscriptionEvent = Event<Listener, Args...>;

public:
    Subscription(SubscriptionEvent& event, Listener* listener);
    ~Subscription();

private:
    SubscriptionEvent& m_event;
    Listener* m_listener;
};


} // namespace JCore


#include "JCore/Event/Subscription.ipp"
