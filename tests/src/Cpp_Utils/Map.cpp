#include "Cpp_Utils/Map.hpp"

#include <string>
#include <stdexcept>
#include <gtest/gtest.h>

#include "Cpp_Utils/Test.hpp"


using std::map;
using std::string;
using std::runtime_error;


namespace Cpp_Utils
{


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// contains_key() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(map_contains_key_Test, valid_map)
{
    const map<string, const string> valid_map
    {
        { "key0" , "value0" },
        { "key1" , "value1" },
        { "key2" , "value2" },
    };

    ASSERT_TRUE(contains_key(valid_map, string("key0")));
    ASSERT_TRUE(contains_key(valid_map, string("key1")));
    ASSERT_TRUE(contains_key(valid_map, string("key2")));
    ASSERT_FALSE(contains_key(valid_map, string("key3")));
    ASSERT_FALSE(contains_key(valid_map, string("value0")));
}


TEST(map_contains_key_Test, empty_map)
{
    const map<string, const string> empty_map;
    ASSERT_FALSE(contains_key(empty_map, string("key0")));
    ASSERT_FALSE(contains_key(empty_map, string("")));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// get_values() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(get_values_Test, valid_map)
{
    const map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    assert_equal_elements({ 0, 1, 2 }, get_values(valid_map));
}


TEST(get_values_Test, empty_map)
{
    const map<string, const int> empty_map;
    assert_equal_elements({}, get_values(empty_map));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// at_key() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(at_key_Test, valid_key)
{
    const map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    assert_no_throw([&]() -> void
    {
        ASSERT_EQ(at_key(valid_map, string("key1")), 1);
    });
}


TEST(at_key_Test, invalid_key)
{
    const map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    ASSERT_THROW(at_key(valid_map, string("key3")), runtime_error);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// at_value() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(at_value_Test, valid_value)
{
    const map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    assert_no_throw([&]() -> void
    {
        ASSERT_TRUE(at_value(valid_map, 1) == string("key1"));
    });
}


TEST(at_value_Test, invalid_value)
{
    const map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    ASSERT_THROW(at_value(valid_map, 3), runtime_error);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// at_index() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(at_index_Test, valid_index)
{
    const map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    assert_no_throw([&]() -> void
    {
        ASSERT_TRUE(at_index(valid_map, 1).first == string("key1"));
    });
}


TEST(at_index_Test, invalid_index)
{
    const map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    ASSERT_THROW(at_index(valid_map, 4), runtime_error);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// remove() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(remove_Test, valid_key)
{
    map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    remove(valid_map, string("key1"));
    ASSERT_FALSE(contains_key(valid_map, string("key1")));
}


TEST(remove_Test, invalid_key)
{
    map<string, const int> valid_map
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    ASSERT_THROW(remove(valid_map, string("key3")), runtime_error);
}


} // namespace Cpp_Utils
