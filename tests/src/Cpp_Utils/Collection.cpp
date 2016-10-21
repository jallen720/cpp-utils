#include "Cpp_Utils/Collection.hpp"

#include <stdexcept>

#include "Cpp_Utils/Container/Fixtures.hpp"
#include "Cpp_Utils/Test.hpp"
#include "Cpp_Utils/String.hpp"


using std::vector;
using std::map;
using std::string;
using std::runtime_error;
using std::domain_error;


namespace Cpp_Utils
{


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// for_each() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(for_each_Test, for_each_vector)
{
    int result = 0;
    const vector<int> values { 1, 2, 3, 4 };
    const auto value_handler = [&](const int value) -> void { result += value; };

    for_each(values, value_handler);
    ASSERT_EQ(result, 10);
    for_each(values, value_handler);
    ASSERT_EQ(result, 20);
}


TEST_F(for_each_Test, for_each_empty_vector)
{
    // Function passed to for_each() should never be called if vector is empty.
    for_each(vector<int> {}, [](const int /*value*/) -> void { FAIL(); });
}


TEST_F(for_each_Test, for_each_map)
{
    vector<string> result;

    const map<string, const int> values
    {
        { "first"  , 3 },
        { "second" , 1 },
        { "third"  , 2 },
    };

    for_each(values, [&](const string & key, const int value) -> void
    {
        result.push_back(key + to_string(value));
    });

    assert_equal_elements(
        {
            "first3",
            "second1",
            "third2",
        },
        result);
}


TEST_F(for_each_Test, for_each_empty_map)
{
    // Function passed to for_each() should never be called if map is empty.
    for_each(map<string, int> {}, [](const string & /*key*/, const int /*value*/) -> void { FAIL(); });
}


TEST_F(for_each_Test, for_each_json)
{
    const vector<string> expected_keys
    {
        "key0",
        "key1",
        "key2",
    };

    const vector<int> expected_values { 0, 1, 2 };
    vector<string> actual_keys;
    vector<int> actual_values;

    for_each(key_value_pairs, [&](const string & key, const int value) -> void
    {
        actual_keys.push_back(key);
        actual_values.push_back(value);
    });

    assert_equal_elements(expected_keys, actual_keys);
    assert_equal_elements(expected_values, actual_values);
}


TEST_F(for_each_Test, unalphabetical_keys_iterated_alphabetically)
{
    const vector<string> expected_keys { "a", "b", "c", "d", "e", "f" };
    vector<string> actual_keys;
    const JSON json = read_json_file(valid_resource_path("json", "unalphabetical_keys.json"));

    for_each(json, [&](const string & key, const JSON &) -> void
    {
        actual_keys.push_back(key);
    });

    assert_equal_elements(expected_keys, actual_keys);
}


TEST_F(for_each_Test, different_json_types)
{
    const JSON json = read_json_file(valid_resource_path("json", "types.json"));
    const auto callback = [](const string &, const JSON &) -> void {};

    assert_no_throw([&]() -> void { for_each(json["object"], callback); });
    ASSERT_THROW(for_each(json["list"], callback), runtime_error);
    ASSERT_THROW(for_each(json["key"], callback), runtime_error);
}


TEST_F(for_each_Test, incorrect_value_type)
{
    const auto callback = [](const string &, const string &) -> void {};

    // key_value_pairs has values of type int, so passing a callback that takes a string as the value
    // type will fail.
    ASSERT_THROW(for_each(key_value_pairs, callback), domain_error);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// find() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(find_Test, matching_predicate)
{
    const vector<int> values { 1, 2, 3, 4 };
    int value = 0;

    ASSERT_TRUE(find(value, values, [](const int value) -> bool { return value > 2; }));
    ASSERT_EQ(value, 3);
}


TEST(find_Test, non_matching_predicate)
{
    const vector<int> values { 1, 2, 3, 4 };
    int value = 0;

    ASSERT_FALSE(find(value, values, [](const int value) -> bool { return value > 4; }));
    ASSERT_EQ(value, 0);
}


} // namespace Cpp_Utils
