#include <stdexcept>

#include "JCore/Errors/Validators/validateNotNull.hpp"
#include "JCore/VectorUtils/remove.hpp"
#include "JCore/VectorUtils/contains.hpp"


namespace JCore {


template<typename Listener, typename ...Args>
Event<Listener, Args...>::Event(OnEventFunc onEventFunc)
    : m_onEventFunc(onEventFunc)
{}


template<typename Listener, typename ...Args>
void Event<Listener, Args...>::subscribe(Listener* listener) {
    validateNotNull("listener", "Event<>::subscribe", listener);
    validateCanSubscribe(listener);
    m_listeners.push_back(listener);
}


template<typename Listener, typename ...Args>
void Event<Listener, Args...>::unsubscribe(Listener* listener) {
    validateNotNull("listener", "Event<>::unsubscribe", listener);
    validateCanUnsubscribe(listener);
    remove(m_listeners, listener);
}


template<typename Listener, typename ...Args>
void Event<Listener, Args...>::trigger(Args... args) {
    for (Listener* listener : m_listeners) {
        ((listener)->*(m_onEventFunc))(args...);
    }
}


template<typename Listener, typename ...Args>
bool Event<Listener, Args...>::isSubscribed(Listener* listener) {
    return JCore::contains(m_listeners, listener);
}


template<typename Listener, typename ...Args>
void Event<Listener, Args...>::validateCanSubscribe(Listener* listener) {
    if (isSubscribed(listener)) {
        throw std::runtime_error("can't subscribe duplicate listeners to an event");
    }
}


template<typename Listener, typename ...Args>
void Event<Listener, Args...>::validateCanUnsubscribe(Listener* listener) {
    if (!isSubscribed(listener)) {
        throw std::runtime_error(
                  "can't unsubscribe listener as it is not currently subscribed "
                  "to this event");
    }
}


} // namespace JCore
