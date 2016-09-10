#include "CppUtils/String.hpp"

#include <string>
#include <vector>
#include <stdexcept>
#include <gtest/gtest.h>

#include "CppUtils/Test.hpp"


using std::string;
using std::vector;
using std::runtime_error;


namespace CppUtils
{


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// areEqual() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(areEqualTest, stringAndCString)
{
    ASSERT_TRUE(areEqual(string("test"), "test"));
    ASSERT_FALSE(areEqual(string("test1"), "test"));
}


TEST(areEqualTest, cStrings)
{
    ASSERT_TRUE(areEqual("test", "test"));
    ASSERT_FALSE(areEqual("test1", "test"));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// isEmpty() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(isEmptyTest, validStrings)
{
    ASSERT_TRUE(isEmpty(""));
    ASSERT_TRUE(isEmpty("\0"));
    ASSERT_FALSE(isEmpty("not empty"));
}


TEST(isEmptyTest, nullString)
{
    ASSERT_THROW(isEmpty(nullptr), runtime_error);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// split() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(splitTest, successfulSplit)
{
    assertEqualElements(
        { "this", "is", "a", "sentence!" },
        split("this is a sentence!", ' '));
}


TEST(splitTest, emptyString)
{
    assertEqualElements(vector<string>(), split("", ' '));
}


TEST(splitTest, emptyStringsAroundDelimiter)
{
    assertEqualElements({ "", "src1" } , split("=src1" , '='));
    assertEqualElements({ "test" }     , split("test=" , '='));
    assertEqualElements({ "" }         , split("="     , '='));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// toString() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(toStringTest, validStrings)
{
    ASSERT_EQ(toString(1)     , "1");
    ASSERT_EQ(toString(1l)    , "1");
    ASSERT_EQ(toString(1ll)   , "1");
    ASSERT_EQ(toString(1u)    , "1");
    ASSERT_EQ(toString(1ul)   , "1");
    ASSERT_EQ(toString(1ull)  , "1");
    ASSERT_EQ(toString(1.0f)  , "1.000000");
    ASSERT_EQ(toString(1.0)   , "1.000000");
    ASSERT_EQ(toString(1.0l)  , "1.000000");
    ASSERT_EQ(toString(true)  , "true");
    ASSERT_EQ(toString(false) , "false");
}


} // namespace CppUtils
