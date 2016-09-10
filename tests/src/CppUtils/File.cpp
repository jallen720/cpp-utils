#include "CppUtils/File.hpp"

#include <stdexcept>
#include <gtest/gtest.h>

#include "CppUtils/String.hpp"
#include "CppUtils/Test.hpp"


using std::string;
using std::vector;
using std::runtime_error;


namespace CppUtils
{


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// directify() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(directify_Test, valid_directory)
{
    ASSERT_TRUE(are_equal(directify("directory/"), "directory/"));
}


TEST(directify_Test, invalid_directory)
{
    ASSERT_TRUE(are_equal(directify("directory"), "directory/"));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// read_file() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(read_file_Test, valid_file)
{
    assert_no_throw([]() -> void
    {
        read_file(valid_resource_path("misc", "test.txt"));
    });
}


TEST(read_file_Test, non_existant_file)
{
    ASSERT_THROW(read_file("does_not_exist"), runtime_error);
}


TEST(read_file_Test, empty_path)
{
    ASSERT_THROW(read_file(""), runtime_error);
}


TEST(read_file_Test, content_match)
{
    const string expectedContent =
        "line1\n"
        "line2\n"
        "line3\n";

    ASSERT_EQ(expectedContent, read_file(valid_resource_path("misc", "test.txt")));
}


} // namespace CppUtils
