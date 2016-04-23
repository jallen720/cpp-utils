#include <typeinfo>


namespace JCore {


template<typename T>
Type typeOf() {
    return Type(typeid(T));
}


} // namespace JCore
