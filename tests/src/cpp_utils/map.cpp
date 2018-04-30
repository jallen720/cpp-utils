#include <string>
#include <stdexcept>
#include "cpp_utils/map.hpp"
#include "cpp_utils/test.hpp"

using std::map;
using std::string;
using std::runtime_error;

namespace Cpp_Utils
{

TEST_CASE("map::map_contains_key() - valid map", "[map][map_contains_key]")
{
    const map<string, const string> valid_map
    {
        { "key0" , "value0" },
        { "key1" , "value1" },
        { "key2" , "value2" },
    };

    REQUIRE(contains_key(valid_map, string("key0")));
    REQUIRE(contains_key(valid_map, string("key1")));
    REQUIRE(contains_key(valid_map, string("key2")));
    REQUIRE_FALSE(contains_key(valid_map, string("key3")));
    REQUIRE_FALSE(contains_key(valid_map, string("value0")));
}

TEST_CASE("map::map_contains_key() - empty map", "[map][map_contains_key]")
{
    const map<string, const string> empty_map;
    REQUIRE_FALSE(contains_key(empty_map, string("key0")));
    REQUIRE_FALSE(contains_key(empty_map, string("")));
}

TEST_CASE("map::get_values() - valid map", "[map][get_values]")
{
    const map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    assert_equal_elements({ 0, 1, 2 }, get_values(valid_map));
}

TEST_CASE("map::get_values() - empty map", "[map][get_values]")
{
    const map<string, const int> empty_map;
    assert_equal_elements({}, get_values(empty_map));
}

TEST_CASE("map::at_key() - valid key", "[map][at_key]")
{
    const map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    assert_no_throw([&]() -> void
    {
        REQUIRE(at_key(valid_map, string("key1")) == 1);
    });
}

TEST_CASE("map::at_key() - invalid key", "[map][at_key]")
{
    const map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    REQUIRE_THROWS_AS(at_key(valid_map, string("key3")), runtime_error);
}

TEST_CASE("map::at_value() - valid value", "[map][at_value]")
{
    const map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    assert_no_throw([&]() -> void
    {
        REQUIRE(at_value(valid_map, 1) == string("key1"));
    });
}

TEST_CASE("map::at_value() - invalid value", "[map][at_value]")
{
    const map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    REQUIRE_THROWS_AS(at_value(valid_map, 3), runtime_error);
}

TEST_CASE("map::at_index() - valid index", "[map][at_index]")
{
    const map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    assert_no_throw([&]() -> void
    {
        REQUIRE(at_index(valid_map, 1).first == string("key1"));
    });
}

TEST_CASE("map::at_index() - invalid index", "[map][at_index]")
{
    const map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    REQUIRE_THROWS_AS(at_index(valid_map, 4), runtime_error);
}

TEST_CASE("map::remove() - valid key", "[map][remove]")
{
    map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    remove(valid_map, string("key1"));
    REQUIRE_FALSE(contains_key(valid_map, string("key1")));
}

TEST_CASE("map::remove() - invalid key", "[map][remove]")
{
    map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    REQUIRE_THROWS_AS(remove(valid_map, string("key3")), runtime_error);
}

} // namespace Cpp_Utils
