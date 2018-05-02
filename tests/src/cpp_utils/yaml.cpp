#include <vector>
#include <string>
#include <stdexcept>
#include "cpp_utils/yaml.hpp"
#include "cpp_utils/test.hpp"

using std::vector;
using std::string;
using std::runtime_error;
using YAML::Node;

namespace cpp_utils
{

TEST_CASE("yaml::read_yaml() - valid yaml", "[yaml][read_yaml]")
{
    assert_no_throw([]() -> void
    {
        read_yaml("key: value");
    });
}

TEST_CASE("yaml::read_yaml() - parse error", "[yaml][read_yaml]")
{
    REQUIRE_THROWS_AS(read_yaml("key: value with extra colon :"), runtime_error);
}

TEST_CASE("yaml::read_yaml_file() - load valid file", "[yaml][read_yaml_file]")
{
    assert_no_throw([]() -> void
    {
        read_yaml_file(valid_resource_path("yaml", "test_config.yaml"));
    });
}

TEST_CASE("yaml::read_yaml_file() - empty path", "[yaml][read_yaml_file]")
{
    REQUIRE_THROWS_AS(read_yaml_file(""), runtime_error);
}

TEST_CASE("yaml::read_yaml_file() - parse error", "[yaml][read_yaml_file]")
{
    REQUIRE_THROWS_AS(read_yaml_file(invalid_resource_path("yaml", "parse_error.yaml")), runtime_error);
}

TEST_CASE("yaml::yaml_contains_key() - valid yaml", "[yaml][yaml_contains_key]")
{
    const Node valid_yaml = read_yaml(R"(
        key0: value0
        key1: value1
        key2: value2
        )");

    REQUIRE(contains_key(valid_yaml, "key0"));
    REQUIRE(contains_key(valid_yaml, "key1"));
    REQUIRE(contains_key(valid_yaml, "key2"));
    REQUIRE_FALSE(contains_key(valid_yaml, "key3"));
    REQUIRE_FALSE(contains_key(valid_yaml, "value0"));
}

TEST_CASE("yaml::yaml_contains_key() - empty yaml", "[yaml][yaml_contains_key]")
{
    const Node empty_yaml;
    REQUIRE_FALSE(contains_key(empty_yaml, "key0"));
    REQUIRE_FALSE(contains_key(empty_yaml, ""));
}

TEST_CASE("yaml::yaml_get_type_name() - valid types", "[yaml][yaml_get_type_name]")
{
    const Node yaml = read_yaml(R"(
        null_key: null
        scalar: 1
        sequence: [ 1, 2, 3 ]
        map:
            key: 2
            sequence: [ 1, 2, 3 ]
        )");

    REQUIRE(get_type_name(yaml["null_key"]) == "null");
    REQUIRE(get_type_name(yaml["scalar"]) == "scalar");
    REQUIRE(get_type_name(yaml["sequence"]) == "sequence");
    REQUIRE(get_type_name(yaml["map"]) == "map");
    REQUIRE(get_type_name(yaml["map"]["key"]) == "scalar");
    REQUIRE(get_type_name(yaml["map"]["sequence"]) == "sequence");
}

TEST_CASE("yaml::yaml_merge() - flat yaml", "[yaml][yaml_merge]")
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
    REQUIRE(contains_key(merged, "key_a"));
    REQUIRE(contains_key(merged, "key_b"));
    REQUIRE(contains_key(merged, "key_c"));
    REQUIRE(contains_key(merged, "key_d"));
    REQUIRE(contains_key(merged, "key_e"));
    REQUIRE(merged["key_a"].as<int>() == 0);
    REQUIRE(merged["key_b"].as<int>() == 1);
    REQUIRE(merged["key_c"].as<int>() == 3);
    REQUIRE(merged["key_d"].as<int>() == 4);
    REQUIRE(merged["key_e"].as<int>() == 5);
}

TEST_CASE("yaml::yaml_merge() - deep yaml", "[yaml][yaml_merge]")
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
    REQUIRE(contains_key(merged, "key_a"));
    REQUIRE(contains_key(merged, "key_b"));
    const Node & key_b = merged["key_b"];
    REQUIRE(contains_key(key_b, "key_c"));
    REQUIRE(contains_key(key_b, "key_d"));
    REQUIRE(merged["key_a"].as<int>() == 0);
    REQUIRE(key_b["key_c"].as<string>() == "test_b");
    const vector<int> key_d = key_b["key_d"].as<vector<int>>();


    // Node doesn't support comparison, so duplicate sequence elements are left in.
    REQUIRE(key_d.size() == 4);
    assert_equal_elements(key_d, { 2, 3, 2, 5 });
}

TEST_CASE("yaml::yaml_merge() - mismatched types", "[yaml][yaml_merge]")
{
    const Node yaml_a = read_yaml(R"(key_a: [ 1, 2 ])");
    const Node yaml_b = read_yaml(R"(key_a: true)");
    REQUIRE_THROWS_AS(merge(yaml_a, yaml_b), runtime_error);
}

} // namespace cpp_utils
