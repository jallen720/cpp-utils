#include <vector>
#include <string>
#include <stdexcept>
#include "Cpp_Utils/JSON.hpp"
#include "Cpp_Utils/Test.hpp"

using std::vector;
using std::string;
using std::runtime_error;


namespace Cpp_Utils
{


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// read_json_file() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("json::read_json_file() - load valid file", "[json][read_json_file]")
{
    assert_no_throw([]() -> void
    {
        read_json_file(valid_resource_path("json", "test_config.json"));
    });
}


TEST_CASE("json::read_json_file() - empty path", "[json][read_json_file]")
{
    REQUIRE_THROWS_AS(read_json_file(""), runtime_error);
}


TEST_CASE("json::read_json_file() - empty file", "[json][read_json_file]")
{
    REQUIRE_THROWS_AS(read_json_file(invalid_resource_path("json", "empty.json")), runtime_error);
}


TEST_CASE("json::read_json_file() - parse error", "[json][read_json_file]")
{
    REQUIRE_THROWS_AS(read_json_file(invalid_resource_path("json", "parse_error.json")), runtime_error);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// contains_key() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("json::json_contains_key() - valid json", "[json][json_contains_key]")
{
    const JSON valid_json
    {
        { "key0" , "value0" },
        { "key1" , "value1" },
        { "key2" , "value2" },
    };

    REQUIRE(contains_key(valid_json, "key0"));
    REQUIRE(contains_key(valid_json, "key1"));
    REQUIRE(contains_key(valid_json, "key2"));
    REQUIRE_FALSE(contains_key(valid_json, "key3"));
    REQUIRE_FALSE(contains_key(valid_json, "value0"));
}


TEST_CASE("json::json_contains_key() - empty json", "[json][json_contains_key]")
{
    const JSON empty_json;
    REQUIRE_FALSE(contains_key(empty_json, "key0"));
    REQUIRE_FALSE(contains_key(empty_json, ""));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// get_type_name() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("json::json_get_type_name() - valid types", "[json][json_get_type_name]")
{
    const JSON json = R"(
        {
            "null": null,
            "boolean": true,
            "number": 1,
            "string": "value",
            "array": [ 1, 2, 3 ],
            "object":
            {
                "key": "value"
            }
        })"_json;

    REQUIRE(get_type_name(json["null"]) == "null");
    REQUIRE(get_type_name(json["boolean"]) == "boolean");
    REQUIRE(get_type_name(json["number"]) == "number");
    REQUIRE(get_type_name(json["string"]) == "string");
    REQUIRE(get_type_name(json["array"]) == "array");
    REQUIRE(get_type_name(json["object"]) == "object");
    REQUIRE(get_type_name(json["object"]["key"]) == "string");
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// merge() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("json::json_merge() - flat json", "[json][json_merge]")
{
    const JSON json_a = R"(
        {
            "key_a": 0,
            "key_b": 1,
            "key_c": 2
        })"_json;

    const JSON json_b = R"(
        {
            "key_c": 3,
            "key_d": 4,
            "key_e": 5
        })"_json;

    JSON merged = merge(json_a, json_b);
    REQUIRE(contains_key(merged, "key_a"));
    REQUIRE(contains_key(merged, "key_b"));
    REQUIRE(contains_key(merged, "key_c"));
    REQUIRE(contains_key(merged, "key_d"));
    REQUIRE(contains_key(merged, "key_e"));
    REQUIRE(merged["key_a"].get<int>() == 0);
    REQUIRE(merged["key_b"].get<int>() == 1);
    REQUIRE(merged["key_c"].get<int>() == 3);
    REQUIRE(merged["key_d"].get<int>() == 4);
    REQUIRE(merged["key_e"].get<int>() == 5);
}


TEST_CASE("json::json_merge() - deep json", "[json][json_merge]")
{
    const JSON json_a = R"(
        {
            "key_a": 0,
            "key_b":
            {
                "key_c": "test_a",
                "key_d":
                [
                    2,
                    3
                ]
            }
        })"_json;

    const JSON json_b = R"(
        {
            "key_b":
            {
                "key_c": "test_b",
                "key_d":
                [
                    2,
                    5
                ]
            }
        })"_json;

    JSON merged = merge(json_a, json_b);
    REQUIRE(contains_key(merged, "key_a"));
    REQUIRE(contains_key(merged, "key_b"));
    const JSON & key_b = merged["key_b"];
    REQUIRE(contains_key(key_b, "key_c"));
    REQUIRE(contains_key(key_b, "key_d"));
    REQUIRE(merged["key_a"].get<int>() == 0);
    REQUIRE(key_b["key_c"].get<string>() == "test_b");
    const vector<int> key_d = key_b["key_d"];
    REQUIRE(key_d.size() == 3);
    assert_equal_elements(key_d, { 2, 3, 5 });
}


TEST_CASE("json::json_merge() - mismatched types", "[json][json_merge]")
{
    const JSON json_a = R"({ "key_a": 0 })"_json;
    const JSON json_b = R"({ "key_a": true })"_json;
    REQUIRE_THROWS_AS(merge(json_a, json_b), runtime_error);
}


} // namespace Cpp_Utils
