#include <typeinfo>


namespace CppUtils
{


template<typename T>
Type type_of()
{
    return Type(typeid(T));
}


} // namespace CppUtils
