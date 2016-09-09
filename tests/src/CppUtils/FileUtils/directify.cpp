#include "CppUtils/FileUtils/directify.hpp"

#include <gtest/gtest.h>

#include "CppUtils/StringUtils/areEqual.hpp"


namespace CppUtils
{


TEST(directifyTest, validDirectory)
{
    ASSERT_TRUE(areEqual(directify("directory/"), "directory/"));
}


TEST(directifyTest, invalidDirectory)
{
    ASSERT_TRUE(areEqual(directify("directory"), "directory/"));
}


} // namespace CppUtils
