#include "CppUtils/Map.hpp"

#include <string>
#include <gtest/gtest.h>

#include "CppUtils/Test.hpp"


using std::map;
using std::string;


namespace CppUtils
{


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// containsKey() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(containsKeyTest, validMap)
{
    const map<string, const string> validMap
    {
        { "key0" , "value0" },
        { "key1" , "value1" },
        { "key2" , "value2" },
    };

    ASSERT_TRUE(containsKey(validMap, string("key0")));
    ASSERT_TRUE(containsKey(validMap, string("key1")));
    ASSERT_TRUE(containsKey(validMap, string("key2")));
    ASSERT_FALSE(containsKey(validMap, string("key3")));
    ASSERT_FALSE(containsKey(validMap, string("value0")));
}


TEST(containsKeyTest, emptyMap)
{
    const map<string, const string> emptyMap;

    ASSERT_FALSE(containsKey(emptyMap, string("key0")));
    ASSERT_FALSE(containsKey(emptyMap, string("")));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// getValues() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(getValuesTest, validMap)
{
    const map<string, const int> validMap
    {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    assertEqualElements({ 0, 1, 2 }, getValues(validMap));
}


TEST(getValuesTest, emptyMap)
{
    const map<string, const int> emptyMap;
    assertEqualElements({}, getValues(emptyMap));
}


} // namespace CppUtils
