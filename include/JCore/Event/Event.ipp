#include "JCore/Errors/Validators/validateNotNull.hpp"
#include "JCore/VectorUtils/remove.hpp"


namespace JCore {


template<typename Listener, typename ...Args>
Event<Listener, Args...>::Event(OnEventFunc onEventFunc)
    : m_onEventFunc(onEventFunc)
{}


template<typename Listener, typename ...Args>
void Event<Listener, Args...>::subscribe(Listener* listener) {
    validateNotNull("listener", "Event<>::subscribe", listener);
    m_listeners.push_back(listener);
}


template<typename Listener, typename ...Args>
void Event<Listener, Args...>::unsubscribe(Listener* listener) {
    validateNotNull("listener", "Event<>::unsubscribe", listener);
    remove(m_listeners, listener);
}


template<typename Listener, typename ...Args>
void Event<Listener, Args...>::trigger(Args... args) {
    for (Listener* listener : m_listeners) {
        ((listener)->*(m_onEventFunc))(args...);
    }
}


} // namespace JCore
