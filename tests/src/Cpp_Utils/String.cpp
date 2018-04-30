#include <string>
#include <vector>
#include <stdexcept>
#include "Cpp_Utils/String.hpp"
#include "Cpp_Utils/Test.hpp"

using std::string;
using std::vector;
using std::runtime_error;


namespace Cpp_Utils
{


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// are_equal() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("string::are_equal() - string and c string", "[string][are_equal]")
{
    REQUIRE(are_equal(string("test"), "test"));
    REQUIRE_FALSE(are_equal(string("test1"), "test"));
}


TEST_CASE("string::are_equal() - c strings", "[string][are_equal]")
{
    REQUIRE(are_equal("test", "test"));
    REQUIRE_FALSE(are_equal("test1", "test"));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// is_empty() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("string::is_empty() - valid strings", "[string][is_empty]")
{
    REQUIRE(is_empty(""));
    REQUIRE(is_empty("\0"));
    REQUIRE_FALSE(is_empty("not empty"));
}


TEST_CASE("string::is_empty() - null string", "[string][is_empty]")
{
    REQUIRE_THROWS_AS(is_empty(nullptr), runtime_error);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// split() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("string::split() - successful split", "[string][split]")
{
    assert_equal_elements(
        { "this", "is", "a", "sentence!" },
        split("this is a sentence!", ' '));
}


TEST_CASE("string::split() - empty string", "[string][split]")
{
    assert_equal_elements(vector<string>(), split("", ' '));
}


TEST_CASE("string::split() - empty strings around delimiter", "[string][split]")
{
    assert_equal_elements({ "", "src1" } , split("=src1" , '='));
    assert_equal_elements({ "test" }     , split("test=" , '='));
    assert_equal_elements({ "" }         , split("="     , '='));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// to_string() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("string::to_string() - valid strings", "[string][to_string]")
{
    REQUIRE(to_string(1) == "1");
    REQUIRE(to_string(1l) == "1");
    REQUIRE(to_string(1ll) == "1");
    REQUIRE(to_string(1u) == "1");
    REQUIRE(to_string(1ul) == "1");
    REQUIRE(to_string(1ull) == "1");
    REQUIRE(to_string(1.0f) == "1.000000");
    REQUIRE(to_string(1.0) == "1.000000");
    REQUIRE(to_string(1.0l) == "1.000000");
    REQUIRE(to_string(true) == "true");
    REQUIRE(to_string(false) == "false");
}


} // namespace Cpp_Utils
