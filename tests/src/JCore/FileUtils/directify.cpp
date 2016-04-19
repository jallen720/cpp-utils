#include "JCore/FileUtils/directify.hpp"

#include <gtest/gtest.h>

#include "JCore/StringUtils/areEqual.hpp"


namespace JCore {


TEST(directifyTest, validDirectory) {
    EXPECT_TRUE(areEqual(directify("directory/"), "directory/"));
}


TEST(directifyTest, invalidDirectory) {
    EXPECT_TRUE(areEqual(directify("directory"), "directory/"));
}


} // namespace JCore
