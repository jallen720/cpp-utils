#include "Cpp_Utils/File.hpp"

#include <stdexcept>
#include <gtest/gtest.h>

#include "Cpp_Utils/String.hpp"
#include "Cpp_Utils/Test.hpp"


using std::string;
using std::vector;
using std::runtime_error;


namespace Cpp_Utils
{


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// directify() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(directify_Test, valid_directory)
{
#ifdef _WIN32
    ASSERT_TRUE(are_equal(directify("directory\\"), "directory\\"));
#elif linux
    ASSERT_TRUE(are_equal(directify("directory/"), "directory/"));
#endif
}


TEST(directify_Test, invalid_directory)
{
#ifdef _WIN32
    ASSERT_TRUE(are_equal(directify("directory"), "directory\\"));
#elif linux
    ASSERT_TRUE(are_equal(directify("directory"), "directory\\"));
#endif
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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// file_exists() Tests
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(file_exists_Test, file_exists)
{
    ASSERT_TRUE(file_exists(valid_resource_path("misc", "test.txt")));
}


TEST(file_exists_Test, file_does_not_exist)
{
    ASSERT_FALSE(file_exists(valid_resource_path("misc", "does_not_exist.txt")));
}


} // namespace Cpp_Utils
