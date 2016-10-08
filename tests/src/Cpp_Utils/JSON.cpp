#include "Cpp_Utils/JSON.hpp"

#include <stdexcept>
#include <gtest/gtest.h>

#include "Cpp_Utils/Test.hpp"


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
TEST(contains_key_Test, valid_json)
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


TEST(contains_key_Test, empty_json)
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


} // namespace Cpp_Utils
