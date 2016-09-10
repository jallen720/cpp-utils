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
// are_equal() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(are_equal_Test, string_and_c_string)
{
    ASSERT_TRUE(are_equal(string("test"), "test"));
    ASSERT_FALSE(are_equal(string("test1"), "test"));
}


TEST(are_equal_Test, c_strings)
{
    ASSERT_TRUE(are_equal("test", "test"));
    ASSERT_FALSE(are_equal("test1", "test"));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// is_empty() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(is_empty_Test, valid_strings)
{
    ASSERT_TRUE(is_empty(""));
    ASSERT_TRUE(is_empty("\0"));
    ASSERT_FALSE(is_empty("not empty"));
}


TEST(is_empty_Test, null_string)
{
    ASSERT_THROW(is_empty(nullptr), runtime_error);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// split() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(split_Test, successful_split)
{
    assert_equal_elements(
        { "this", "is", "a", "sentence!" },
        split("this is a sentence!", ' '));
}


TEST(split_Test, empty_string)
{
    assert_equal_elements(vector<string>(), split("", ' '));
}


TEST(split_Test, empty_strings_around_delimiter)
{
    assert_equal_elements({ "", "src1" } , split("=src1" , '='));
    assert_equal_elements({ "test" }     , split("test=" , '='));
    assert_equal_elements({ "" }         , split("="     , '='));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// to_string() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(to_string_Test, valid_strings)
{
    ASSERT_EQ(to_string(1)     , "1");
    ASSERT_EQ(to_string(1l)    , "1");
    ASSERT_EQ(to_string(1ll)   , "1");
    ASSERT_EQ(to_string(1u)    , "1");
    ASSERT_EQ(to_string(1ul)   , "1");
    ASSERT_EQ(to_string(1ull)  , "1");
    ASSERT_EQ(to_string(1.0f)  , "1.000000");
    ASSERT_EQ(to_string(1.0)   , "1.000000");
    ASSERT_EQ(to_string(1.0l)  , "1.000000");
    ASSERT_EQ(to_string(true)  , "true");
    ASSERT_EQ(to_string(false) , "false");
}


} // namespace CppUtils
