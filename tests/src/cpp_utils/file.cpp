#include <stdexcept>
#include "cpp_utils/file.hpp"
#include "cpp_utils/string.hpp"
#include "cpp_utils/test.hpp"

using std::string;
using std::vector;
using std::runtime_error;

namespace Cpp_Utils
{

TEST_CASE("file::directify() - valid directory", "[file][directify]")
{
#ifdef _WIN32
    REQUIRE(are_equal(directify("directory\\"), "directory\\"));
#elif __gnu_linux__
    REQUIRE(are_equal(directify("directory/"), "directory/"));
#endif
}

TEST_CASE("file::directify() - invalid directory", "[file][directify]")
{
#ifdef _WIN32
    REQUIRE(are_equal(directify("directory"), "directory\\"));
#elif __gnu_linux__
    REQUIRE(are_equal(directify("directory"), "directory/"));
#endif
}

TEST_CASE("file::platform_path() - valid path", "[file][platform_path]")
{
#ifdef _WIN32
    REQUIRE(are_equal(platform_path("platform/path/"), "platform\\path\\"));
#elif __gnu_linux__
    REQUIRE(are_equal(platform_path("platform/path/"), "platform/path/"));
#endif
}

TEST_CASE("file::read_file() - valid file", "[file][read_file]")
{
    assert_no_throw([]() -> void
    {
        read_file(valid_resource_path("misc", "test.txt"));
    });
}

TEST_CASE("file::read_file() - non existant file", "[file][read_file]")
{
    REQUIRE_THROWS_AS(read_file("does_not_exist"), runtime_error);
}

TEST_CASE("file::read_file() - empty path", "[file][read_file]")
{
    REQUIRE_THROWS_AS(read_file(""), runtime_error);
}

TEST_CASE("file::read_file() - content match", "[file][read_file]")
{
    const string expectedContent =
        "line1\n"
        "line2\n"
        "line3\n";

    REQUIRE(expectedContent == read_file(valid_resource_path("misc", "test.txt")));
}

TEST_CASE("file::file_exists() - file exists", "[file][file_exists]")
{
    REQUIRE(file_exists(valid_resource_path("misc", "test.txt")));
}

TEST_CASE("file::file_exists() - file does not exist", "[file][file_exists]")
{
    REQUIRE_FALSE(file_exists(valid_resource_path("misc", "does_not_exist.txt")));
}

} // namespace Cpp_Utils
