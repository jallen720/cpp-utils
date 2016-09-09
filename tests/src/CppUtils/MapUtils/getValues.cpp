#include "CppUtils/MapUtils/getValues.hpp"

#include <string>
#include <gtest/gtest.h>

#include "CppUtils/TestUtils/assertEqualElements.hpp"


using std::map;
using std::string;


namespace CppUtils {


TEST(getValuesTest, validMap) {
    const map<string, const int> validMap {
        { "key0" , 0 },
        { "key1" , 1 },
        { "key2" , 2 },
    };

    assertEqualElements({ 0, 1, 2 }, getValues(validMap));
}


TEST(getValuesTest, emptyMap) {
    const map<string, const int> emptyMap;
    assertEqualElements({}, getValues(emptyMap));
}


} // namespace CppUtils
