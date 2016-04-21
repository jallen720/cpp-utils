#include <typeinfo>


namespace JCore {


template<typename T>
std::type_index typeOf() {
    return std::type_index(typeid(T));
}


} // namespace JCore
