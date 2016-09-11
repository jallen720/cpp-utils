#include "Cpp_Utils/Fn.hpp"

#include <vector>
#include <map>
#include <string>
#include <gtest/gtest.h>

#include "Cpp_Utils/Test.hpp"
#include "Cpp_Utils/String.hpp"


using std::vector;
using std::map;
using std::pair;
using std::string;


namespace Cpp_Utils
{


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// accumulate() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static int vector_accumulator(const int accumulation, const int element)
{
    return accumulation + element;
}


TEST(accumulate_Test, accumulate_vector)
{
    const vector<int> numbers { 1, 2, 3 };
    ASSERT_EQ(6, accumulate(0, numbers, vector_accumulator));
}


TEST(accumulate_Test, accumulate_empty_vector)
{
    ASSERT_EQ(0, accumulate(0, vector<int>(), vector_accumulator));
}


static string map_accumulator(const string accumulation, const pair<string, const int> & element)
{
    return accumulation + element.first + ": " + to_string(element.second) + "\n";
}


TEST(accumulate_Test, accumulate_map)
{
    const map<string, const int> mapped_data
    {
        { "first"  , 1 },
        { "second" , 2 },
        { "third"  , 3 },
    };

    ASSERT_EQ(
        "first: 1\n"
        "second: 2\n"
        "third: 3\n",
        accumulate<string>("", mapped_data, map_accumulator));
}


TEST(accumulate_Test, accumulate_empty_map)
{
    ASSERT_EQ("", accumulate<string>("", map<string, const int>(), map_accumulator));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// transform() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static string vector_transformer(const string & element)
{
    return element.back() + element + "!";
}


TEST(transform_Test, transform_vector)
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


TEST(transform_Test, transform_empty_vector)
{
    assert_equal_elements({}, transform<string>(vector<string>(), vector_transformer));
}


static int map_transformer(const pair<int, int> & element)
{
    return element.first + element.second;
}


TEST(transform_Test, transform_map)
{
    const map<int, int> mapped_numbers
    {
        { 1 , 0 },
        { 2 , 3 },
        { 6 , 5 },
    };

    assert_equal_elements({ 1, 5, 11 }, transform<int>(mapped_numbers, map_transformer));
}


TEST(transform_Test, transform_empty_map)
{
    assert_equal_elements({}, transform<int>(map<int, int>(), map_transformer));
}


} // namespace Cpp_Utils
