#include <iostream>
#include <exception>
#include "cpp_utils/test.hpp"
#include "cpp_utils/dependencies/catch.hpp"
#include "cpp_utils/file.hpp"

using std::cerr;
using std::exception;
using std::function;
using std::string;

namespace cpp_utils
{

static const string TESTS_RESOURCES_DIRECTORY = "tests/resources/";

void assert_no_throw(const function<void()> & block)
{
    try
    {
        block();
    }
    catch (const exception & error)
    {
        cerr << "std::exception thrown in test:\n  " << error.what() << "\n";
        FAIL();
    }
    catch (...)
    {
        cerr << "Unknown exception thrown in test!\n";
        FAIL();
    }
}

string invalid_resource_path(const string & sub_directory, const string & name)
{
    return TESTS_RESOURCES_DIRECTORY + "invalid/" + directify(sub_directory) + name;
}

string valid_resource_path(const string & sub_directory, const string & name)
{
    return TESTS_RESOURCES_DIRECTORY + "valid/" + directify(sub_directory) + name;
}

} // namespace cpp_utils
