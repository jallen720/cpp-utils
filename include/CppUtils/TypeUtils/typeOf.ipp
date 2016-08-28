#include <typeinfo>


namespace CppUtils {


template<typename T>
Type typeOf() {
    return Type(typeid(T));
}


} // namespace CppUtils
