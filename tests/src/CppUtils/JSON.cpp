#include "CppUtils/JSON.hpp"

#include <stdexcept>
#include <gtest/gtest.h>

#include "CppUtils/Test.hpp"


using std::runtime_error;


namespace CppUtils
{


TEST(read_json_file_Test, load_valid_file)
{
    assert_no_throw([]() -> void
    {
        read_json_file(valid_resource_path("json", "test_config.json"));
    });
}


TEST(read_json_file_Test, empty_path)
{
    ASSERT_THROW(read_json_file(""), runtime_error);
}


TEST(read_json_file_Test, empty_file)
{
    ASSERT_THROW(read_json_file(invalid_resource_path("json", "empty.json")), runtime_error);
}


TEST(read_json_file_Test, parse_error)
{
    ASSERT_THROW(read_json_file(invalid_resource_path("json", "parse_error.json")), runtime_error);
}


} // namespace CppUtils
