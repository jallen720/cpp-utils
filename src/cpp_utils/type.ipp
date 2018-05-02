#include <typeinfo>

namespace cpp_utils
{

template<typename T>
Type type_of()
{
    return Type(typeid(T));
}

} // namespace cpp_utils
