#include "JCore/MapUtils/hasKey.hpp"

#include <string>
#include <gtest/gtest.h>


using std::map;
using std::string;


namespace JCore {


TEST(hasKeyTest, validMap) {
    static const map<string, string> validMap {
        { "key0", "value0" },
        { "key1", "value1" },
        { "key2", "value2" },
    };

    EXPECT_TRUE(hasKey(validMap, string("key0")));
    EXPECT_TRUE(hasKey(validMap, string("key1")));
    EXPECT_TRUE(hasKey(validMap, string("key2")));
    EXPECT_FALSE(hasKey(validMap, string("key3")));
    EXPECT_FALSE(hasKey(validMap, string("value0")));
}


TEST(hasKeyTest, emptyMap) {
    static const map<string, string> emptyMap;

    EXPECT_FALSE(hasKey(emptyMap, string("key0")));
    EXPECT_FALSE(hasKey(emptyMap, string("")));
}


} // namespace JCore
