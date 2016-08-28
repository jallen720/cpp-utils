#include "CppUtils/MapUtils/containsKey.hpp"

#include <string>
#include <gtest/gtest.h>


using std::map;
using std::string;


namespace CppUtils {


TEST(containsKeyTest, validMap) {
    const map<string, const string> validMap {
        { "key0", "value0" },
        { "key1", "value1" },
        { "key2", "value2" },
    };

    ASSERT_TRUE(containsKey(validMap, string("key0")));
    ASSERT_TRUE(containsKey(validMap, string("key1")));
    ASSERT_TRUE(containsKey(validMap, string("key2")));
    ASSERT_FALSE(containsKey(validMap, string("key3")));
    ASSERT_FALSE(containsKey(validMap, string("value0")));
}


TEST(containsKeyTest, emptyMap) {
    const map<string, const string> emptyMap;

    ASSERT_FALSE(containsKey(emptyMap, string("key0")));
    ASSERT_FALSE(containsKey(emptyMap, string("")));
}


} // namespace CppUtils
