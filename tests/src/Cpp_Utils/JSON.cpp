#include "Cpp_Utils/JSON.hpp"

#include <vector>
#include <string>
#include <stdexcept>
#include <gtest/gtest.h>

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
TEST(read_json_file_Test, load_valid_file)
{
    assert_no_throw([]() -> void
    {
        read_json_file(valid_resource_path("json", "test_config.json"));
    });
}


TEST(read_json_file_Test, empty_path)
{
    ASSERT_THROW(read_json_file(""), runtime_error);
}


TEST(read_json_file_Test, empty_file)
{
    ASSERT_THROW(read_json_file(invalid_resource_path("json", "empty.json")), runtime_error);
}


TEST(read_json_file_Test, parse_error)
{
    ASSERT_THROW(read_json_file(invalid_resource_path("json", "parse_error.json")), runtime_error);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// contains_key() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(json_contains_key_Test, valid_json)
{
    const JSON valid_json
    {
        { "key0" , "value0" },
        { "key1" , "value1" },
        { "key2" , "value2" },
    };

    ASSERT_TRUE(contains_key(valid_json, "key0"));
    ASSERT_TRUE(contains_key(valid_json, "key1"));
    ASSERT_TRUE(contains_key(valid_json, "key2"));
    ASSERT_FALSE(contains_key(valid_json, "key3"));
    ASSERT_FALSE(contains_key(valid_json, "value0"));
}


TEST(json_contains_key_Test, empty_json)
{
    const JSON empty_json;
    ASSERT_FALSE(contains_key(empty_json, "key0"));
    ASSERT_FALSE(contains_key(empty_json, ""));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// get_type_name() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(get_type_name_Test, valid_types)
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

    ASSERT_STREQ(get_type_name(json["null"]).c_str(), "null");
    ASSERT_STREQ(get_type_name(json["boolean"]).c_str(), "boolean");
    ASSERT_STREQ(get_type_name(json["number"]).c_str(), "number");
    ASSERT_STREQ(get_type_name(json["string"]).c_str(), "string");
    ASSERT_STREQ(get_type_name(json["array"]).c_str(), "array");
    ASSERT_STREQ(get_type_name(json["object"]).c_str(), "object");
    ASSERT_STREQ(get_type_name(json["object"]["key"]).c_str(), "string");
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// merge() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(merge_Test, flat_json)
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
    ASSERT_TRUE(contains_key(merged, "key_a"));
    ASSERT_TRUE(contains_key(merged, "key_b"));
    ASSERT_TRUE(contains_key(merged, "key_c"));
    ASSERT_TRUE(contains_key(merged, "key_d"));
    ASSERT_TRUE(contains_key(merged, "key_e"));
    ASSERT_EQ(merged["key_a"].get<int>(), 0);
    ASSERT_EQ(merged["key_b"].get<int>(), 1);
    ASSERT_EQ(merged["key_c"].get<int>(), 3);
    ASSERT_EQ(merged["key_d"].get<int>(), 4);
    ASSERT_EQ(merged["key_e"].get<int>(), 5);
}


TEST(merge_Test, deep_json)
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
    ASSERT_TRUE(contains_key(merged, "key_a"));
    ASSERT_TRUE(contains_key(merged, "key_b"));
    const JSON & key_b = merged["key_b"];
    ASSERT_TRUE(contains_key(key_b, "key_c"));
    ASSERT_TRUE(contains_key(key_b, "key_d"));
    ASSERT_EQ(merged["key_a"].get<int>(), 0);
    ASSERT_STREQ(key_b["key_c"].get<string>().c_str(), "test_b");
    const vector<int> key_d = key_b["key_d"];
    ASSERT_EQ(key_d.size(), 3);
    assert_equal_elements(key_d, { 2, 3, 5 });
}


TEST(merge_Test, mismatched_types)
{
    const JSON json_a = R"({ "key_a": 0 })"_json;
    const JSON json_b = R"({ "key_a": true })"_json;
    ASSERT_THROW(merge(json_a, json_b), runtime_error);
}


} // namespace Cpp_Utils
