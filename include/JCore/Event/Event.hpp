#pragma once


#include <vector>


namespace JCore {


template<typename Listener, typename ...Args>
class Event final {
private:
    using OnEventFunc = void (Listener::*)(Args...);

public:
    explicit Event(OnEventFunc onEventFunc);
    void subscribe(Listener* listener);
    void unsubscribe(Listener* listener);
    void trigger(Args... args);

private:
    OnEventFunc m_onEventFunc;
    std::vector<Listener*> m_listeners;

    bool isSubscribed(Listener* listener);
    void validateCanSubscribe(Listener* listener);
    void validateCanUnsubscribe(Listener* listener);
};


} // namespace JCore


#include "JCore/Event/Event.ipp"
