#include <typeinfo>


namespace JCore {


template<typename T>
std::type_index typeOf() {
    return std::type_index(typeid(T));
}


template<typename Any>
std::type_index typeOf(const Any& value) {
    return std::type_index(typeid(value));
}


} // namespace JCore
