#include "JCore/StringUtils/areEqual.hpp"

#include <string>
#include <gtest/gtest.h>


using std::string;


namespace JCore {


TEST(areEqualTest, stringAndCString) {
    ASSERT_TRUE(areEqual(string("test"), "test"));
    ASSERT_FALSE(areEqual(string("test1"), "test"));
}


TEST(areEqualTest, cStrings) {
    ASSERT_TRUE(areEqual("test", "test"));
    ASSERT_FALSE(areEqual("test1", "test"));
}


} // namespace JCore
