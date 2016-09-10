#include <typeinfo>


namespace Cpp_Utils
{


template<typename T>
Type type_of()
{
    return Type(typeid(T));
}


} // namespace Cpp_Utils
