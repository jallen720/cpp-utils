#include <stdexcept>
#include "Cpp_Utils/Collection.hpp"
#include "Cpp_Utils/Test.hpp"
#include "Cpp_Utils/String.hpp"
#include "Cpp_Utils/JSON.hpp"
#include "Cpp_Utils/YAML.hpp"

using std::vector;
using std::map;
using std::string;
using std::runtime_error;
using std::domain_error;
using YAML::Node;


namespace Cpp_Utils
{


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// for_each() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// for_each(std::vector<T>, Callback) overloads
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("collection::for_each() - for each vector", "[collection][for_each]")
{
    int result = 0;
    const vector<int> values { 1, 2, 3, 4 };
    const auto value_handler = [&](const int value) -> void { result += value; };

    for_each(values, value_handler);
    REQUIRE(result == 10);
    for_each(values, value_handler);
    REQUIRE(result == 20);
}


TEST_CASE("collection::for_each() - for each empty vector", "[collection][for_each]")
{
    // Function passed to for_each() should never be called if vector is empty.
    for_each(vector<int> {}, [](const int /*value*/) -> void { FAIL(); });
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// for_each(std::map<T, U>, Callback) overloads
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("collection::for_each() - for each map", "[collection][for_each]")
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


TEST_CASE("collection::for_each() - incorrect value type", "[collection][for_each]")
{
    const JSON key_value_pairs = read_json_file(valid_resource_path("json", "key_value_pairs.json"));
    const auto callback = [](const string &, const string &) -> void {};

    // key_value_pairs has values of type int, so passing a callback that takes a string as the value
    // type will fail.
    REQUIRE_THROWS_AS(for_each(key_value_pairs, callback), domain_error);
}


TEST_CASE("collection::for_each() - for each empty map", "[collection][for_each]")
{
    // Function passed to for_each() should never be called if map is empty.
    for_each(map<string, int> {}, [](const string & /*key*/, const int /*value*/) -> void { FAIL(); });
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// for_each(std::map<T, U>, std::map<T, U>::iterator, Callback) overloads
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("collection::for_each() - for each map begin", "[collection][for_each]")
{
    vector<string> result;

    const map<string, const int> values
    {
        { "first"  , 3 },
        { "second" , 1 },
        { "third"  , 2 },
    };

    for_each(values, ++values.begin(), [&](const string & key, const int value) -> void
    {
        result.push_back(key + to_string(value));
    });

    assert_equal_elements({ "second1", "third2" }, result);
}


TEST_CASE("collection::for_each() - for each map begin non-const", "[collection][for_each]")
{
    vector<string> result;

    map<string, int> values
    {
        { "first"  , 3 },
        { "second" , 1 },
        { "third"  , 2 },
    };

    for_each(values, ++values.begin(), [&](const string & /*key*/, int & value) -> void
    {
        value++;
    });

    for_each(values, ++values.begin(), [&](const string & key, const int value) -> void
    {
        result.push_back(key + to_string(value));
    });

    assert_equal_elements({ "second2", "third3" }, result);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// for_each(JSON, Callback) overloads
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("collection::for_each() - json", "[collection][for_each]")
{
    const JSON key_value_pairs = read_json_file(valid_resource_path("json", "key_value_pairs.json"));

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


TEST_CASE("collection::for_each() - unalphabetical json keys iterated alphabetically", "[collection][for_each]")
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


TEST_CASE("collection::for_each() - different json types", "[collection][for_each]")
{
    const JSON json = read_json_file(valid_resource_path("json", "types.json"));
    const auto callback = [](const string &, const JSON &) -> void {};

    assert_no_throw([&]() -> void { for_each(json["object"], callback); });
    REQUIRE_THROWS_AS(for_each(json["list"], callback), runtime_error);
    REQUIRE_THROWS_AS(for_each(json["key"], callback), runtime_error);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// for_each(YAML::Node, Callback) overloads
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("collection::for_each() - yaml", "[collection][for_each]")
{
    const Node key_value_pairs = read_yaml_file(valid_resource_path("yaml", "key_value_pairs.yaml"));

    const vector<string> expected_keys
    {
        "key0",
        "key1",
        "key2",
    };

    const vector<int> expected_values { 0, 1, 2 };
    vector<string> actual_keys;
    vector<int> actual_values;

    for_each(key_value_pairs, [&](const string & key, const Node & value) -> void
    {
        actual_keys.push_back(key);
        actual_values.push_back(value.as<int>());
    });

    assert_equal_elements(expected_keys, actual_keys);
    assert_equal_elements(expected_values, actual_values);
}


TEST_CASE("collection::for_each() - unalphabetical yaml keys iterated as is", "[collection][for_each]")
{
    const vector<string> expected_keys { "a", "f", "d", "c", "e", "b" };
    vector<string> actual_keys;
    const Node yaml = read_yaml_file(valid_resource_path("yaml", "unalphabetical_keys.yaml"));

    for_each(yaml, [&](const string & key, const Node &) -> void
    {
        actual_keys.push_back(key);
    });

    assert_equal_elements(expected_keys, actual_keys);
}


TEST_CASE("collection::for_each() - different yaml types", "[collection][for_each]")
{
    const Node yaml = read_yaml_file(valid_resource_path("yaml", "types.yaml"));
    const auto callback = [](const string &, const Node &) -> void {};

    assert_no_throw([&]() -> void { for_each(yaml["map"], callback); });
    REQUIRE_THROWS_AS(for_each(yaml["list"], callback), runtime_error);
    REQUIRE_THROWS_AS(for_each(yaml["key"], callback), runtime_error);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// find() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// find(T, std::vector<T>, Predicate) overloads
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("collection::find() - matching predicate", "[collection][find]")
{
    const vector<int> values { 1, 2, 3, 4 };
    int value = 0;

    REQUIRE(find(value, values, [](const int value) -> bool { return value > 2; }));
    REQUIRE(value == 3);
}


TEST_CASE("collection::find() - non-matching predicate", "[collection][find]")
{
    const vector<int> values { 1, 2, 3, 4 };
    int value = 0;

    REQUIRE_FALSE(find(value, values, [](const int value) -> bool { return value > 4; }));
    REQUIRE(value == 0);
}


} // namespace Cpp_Utils
