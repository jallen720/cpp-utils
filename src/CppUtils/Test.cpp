#include "CppUtils/Test.hpp"

#include <iostream>
#include <exception>
#include <gtest/gtest.h>

#include "CppUtils/File.hpp"


using std::cerr;
using std::exception;
using std::function;
using std::string;


namespace CppUtils
{


void assertNoThrow(const function<void()> & block)
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


string invalidResourcePath(const string & subDirectory, const string & name)
{
    static const string INVALID_RESOURCES_DIRECTORY = "tests/resources/invalid/";

    return INVALID_RESOURCES_DIRECTORY + directify(subDirectory) + name;
}


string validResourcePath(const string & subDirectory, const string & name)
{
    static const string VALID_RESOURCES_DIRECTORY = "tests/resources/valid/";

    return VALID_RESOURCES_DIRECTORY + directify(subDirectory) + name;
}


} // namespace CppUtils
