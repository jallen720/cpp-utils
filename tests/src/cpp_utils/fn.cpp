#include <vector>
#include <map>
#include <string>
#include "cpp_utils/fn.hpp"
#include "cpp_utils/test.hpp"
#include "cpp_utils/string.hpp"

using std::vector;
using std::map;
using std::pair;
using std::string;

namespace cpp_utils
{

static int vector_accumulator(const int accumulation, const int element)
{
    return accumulation + element;
}

TEST_CASE("fn::accumulate() - accumulate vector", "[fn][accumulate]")
{
    const vector<int> numbers { 1, 2, 3 };
    REQUIRE(6 == accumulate(0, numbers, vector_accumulator));
}

TEST_CASE("fn::accumulate() - accumulate empty vector", "[fn][accumulate]")
{
    REQUIRE(0 == accumulate(0, vector<int>(), vector_accumulator));
}

static string map_accumulator(const string accumulation, const pair<string, const int> & element)
{
    return accumulation + element.first + ": " + to_string(element.second) + "\n";
}

TEST_CASE("fn::accumulate() - accumulate map", "[fn][accumulate]")
{
    const map<string, const int> mapped_data
    {
        { "first"  , 1 },
        { "second" , 2 },
        { "third"  , 3 },
    };

    REQUIRE(
        "first: 1\n"
        "second: 2\n"
        "third: 3\n"
        == accumulate<string>("", mapped_data, map_accumulator));
}

TEST_CASE("fn::accumulate() - accumulate empty map", "[fn][accumulate]")
{
    REQUIRE("" == accumulate<string>("", map<string, const int>(), map_accumulator));
}

static string vector_transformer(const string & element)
{
    return element.back() + element + "!";
}

TEST_CASE("fn::transform() - transform vector", "[fn][transform]")
{
    const vector<string> strings
    {
        "string0",
        "string1",
        "string2",
    };

    assert_equal_elements(
        {
            "0string0!",
            "1string1!",
            "2string2!",
        },
        transform<string>(strings, vector_transformer));
}

TEST_CASE("fn::transform() - transform empty vector", "[fn][transform]")
{
    assert_equal_elements({}, transform<string>(vector<string>(), vector_transformer));
}

static int map_transformer(const pair<int, int> & element)
{
    return element.first + element.second;
}

TEST_CASE("fn::transform() - transform map", "[fn][transform]")
{
    const map<int, int> mapped_numbers
    {
        { 1 , 0 },
        { 2 , 3 },
        { 6 , 5 },
    };

    assert_equal_elements({ 1, 5, 11 }, transform<int>(mapped_numbers, map_transformer));
}

TEST_CASE("fn::transform() - transform empty map", "[fn][transform]")
{
    assert_equal_elements({}, transform<int>(map<int, int>(), map_transformer));
}

static bool vector_predicate(int element)
{
    return element > 2;
}

TEST_CASE("fn::filter() - filter vector", "[fn][filter]")
{
    const vector<int> numbers = { 1, 2, 3, 4 };
    assert_equal_elements({ 3, 4 }, filter(numbers, vector_predicate));
}

TEST_CASE("fn::filter() - filter empty vector", "[fn][filter]")
{
    assert_equal_elements({}, filter(vector<int>(), vector_predicate));
}

} // namespace cpp_utils
