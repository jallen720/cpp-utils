#include "Cpp_Utils/YAML.hpp"

#include <vector>
#include <string>
#include <stdexcept>
#include <gtest/gtest.h>

#include "Cpp_Utils/Test.hpp"


using std::vector;
using std::string;
using std::runtime_error;

// yaml-cpp/yaml.h
using YAML::Node;


namespace Cpp_Utils
{


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// read_yaml() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(read_yaml_Test, valid_yaml)
{
    assert_no_throw([]() -> void
    {
        read_yaml("key: value");
    });
}


TEST(read_yaml_Test, parse_error)
{
    ASSERT_THROW(read_yaml("key: value with extra colon :"), runtime_error);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// read_yaml_file() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(read_yaml_file_Test, load_valid_file)
{
    assert_no_throw([]() -> void
    {
        read_yaml_file(valid_resource_path("yaml", "test_config.yaml"));
    });
}


TEST(read_yaml_file_Test, empty_path)
{
    ASSERT_THROW(read_yaml_file(""), runtime_error);
}


TEST(read_yaml_file_Test, parse_error)
{
    ASSERT_THROW(read_yaml_file(invalid_resource_path("yaml", "parse_error.yaml")), runtime_error);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// contains_key() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(yaml_contains_key_Test, valid_yaml)
{
    const Node valid_yaml = read_yaml(R"(
        key0: value0
        key1: value1
        key2: value2
        )");

    ASSERT_TRUE(contains_key(valid_yaml, "key0"));
    ASSERT_TRUE(contains_key(valid_yaml, "key1"));
    ASSERT_TRUE(contains_key(valid_yaml, "key2"));
    ASSERT_FALSE(contains_key(valid_yaml, "key3"));
    ASSERT_FALSE(contains_key(valid_yaml, "value0"));
}


TEST(yaml_contains_key_Test, empty_yaml)
{
    const Node empty_yaml;
    ASSERT_FALSE(contains_key(empty_yaml, "key0"));
    ASSERT_FALSE(contains_key(empty_yaml, ""));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// get_type_name() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(yaml_get_type_name_Test, valid_types)
{
    const Node yaml = read_yaml(R"(
        null_key: null
        scalar: 1
        sequence: [ 1, 2, 3 ]
        map:
            key: 2
            sequence: [ 1, 2, 3 ]
        )");

    ASSERT_STREQ(get_type_name(yaml["null_key"]).c_str(), "null");
    ASSERT_STREQ(get_type_name(yaml["scalar"]).c_str(), "scalar");
    ASSERT_STREQ(get_type_name(yaml["sequence"]).c_str(), "sequence");
    ASSERT_STREQ(get_type_name(yaml["map"]).c_str(), "map");
    ASSERT_STREQ(get_type_name(yaml["map"]["key"]).c_str(), "scalar");
    ASSERT_STREQ(get_type_name(yaml["map"]["sequence"]).c_str(), "sequence");
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// merge() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(yaml_merge_Test, flat_yaml)
{
    const Node yaml_a = read_yaml(R"(
        key_a: 0
        key_b: 1
        key_c: 2
        )");

    const Node yaml_b = read_yaml(R"(
        key_c: 3
        key_d: 4
        key_e: 5
        )");

    Node merged = merge(yaml_a, yaml_b);
    ASSERT_TRUE(contains_key(merged, "key_a"));
    ASSERT_TRUE(contains_key(merged, "key_b"));
    ASSERT_TRUE(contains_key(merged, "key_c"));
    ASSERT_TRUE(contains_key(merged, "key_d"));
    ASSERT_TRUE(contains_key(merged, "key_e"));
    ASSERT_EQ(merged["key_a"].as<int>(), 0);
    ASSERT_EQ(merged["key_b"].as<int>(), 1);
    ASSERT_EQ(merged["key_c"].as<int>(), 3);
    ASSERT_EQ(merged["key_d"].as<int>(), 4);
    ASSERT_EQ(merged["key_e"].as<int>(), 5);
}


TEST(yaml_merge_Test, deep_yaml)
{
    const Node yaml_a = read_yaml(R"(
        key_a: 0
        key_b:
            key_c: test_a
            key_d: [ 2, 3 ]
        )");

    const Node yaml_b = read_yaml(R"(
        key_b:
            key_c: test_b
            key_d: [ 2, 5 ]
        )");

    Node merged = merge(yaml_a, yaml_b);
    ASSERT_TRUE(contains_key(merged, "key_a"));
    ASSERT_TRUE(contains_key(merged, "key_b"));
    const Node & key_b = merged["key_b"];
    ASSERT_TRUE(contains_key(key_b, "key_c"));
    ASSERT_TRUE(contains_key(key_b, "key_d"));
    ASSERT_EQ(merged["key_a"].as<int>(), 0);
    ASSERT_STREQ(key_b["key_c"].as<string>().c_str(), "test_b");
    const vector<int> key_d = key_b["key_d"].as<vector<int>>();


    // Node doesn't support comparison, so duplicate sequence elements are left in.
    ASSERT_EQ(key_d.size(), 4);
    assert_equal_elements(key_d, { 2, 3, 2, 5 });
}


TEST(yaml_merge_Test, mismatched_types)
{
    const Node yaml_a = read_yaml(R"(key_a: [ 1, 2 ])");
    const Node yaml_b = read_yaml(R"(key_a: true)");
    ASSERT_THROW(merge(yaml_a, yaml_b), runtime_error);
}


} // namespace Cpp_Utils
