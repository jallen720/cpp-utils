#include "cpp_utils/dependencies/catch.hpp"
#include "cpp_utils/type.hpp"

namespace cpp_utils
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

} // namespace cpp_utils
