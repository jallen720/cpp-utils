#include "Cpp_Utils/__internal__/catch.hpp"
#include "Cpp_Utils/Type.hpp"


namespace Cpp_Utils
{


TEST_CASE("type::type_of() - equal types", "[type][type_of]")
{
    REQUIRE(type_of<int>() == type_of<int>());
    REQUIRE(type_of<int &>() == type_of<int>());
    REQUIRE_FALSE(type_of<float>() == type_of<int>());
    REQUIRE_FALSE(type_of<int *>() == type_of<int>());
}


TEST_CASE("type::type_of() - types with cv qualifiers", "[type][type_of]")
{
    REQUIRE(type_of<const int>() == type_of<int>());
    REQUIRE(type_of<const int &>() == type_of<int>());
    REQUIRE(type_of<int * const>() == type_of<int *>());
    REQUIRE(type_of<const int *>() == type_of<const int *>());
    REQUIRE(type_of<const int * const>() == type_of<const int *>());
}


} // namespace Cpp_Utils
