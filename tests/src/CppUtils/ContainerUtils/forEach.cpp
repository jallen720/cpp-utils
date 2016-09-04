#include "CppUtils/ContainerUtils/forEach.hpp"

#include <gtest/gtest.h>

#include "CppUtils/TestUtils/assertEqualElements.hpp"
#include "CppUtils/StringUtils/toString.hpp"


using std::vector;
using std::map;
using std::string;


namespace CppUtils {


TEST(forEachTest, forEachVector) {
    int result = 0;
    const vector<int> values { 1, 2, 3, 4 };
    const auto valueHandler = [&](const int value) -> void { result += value; };

    forEach(values, valueHandler);
    ASSERT_EQ(result, 10);
    forEach(values, valueHandler);
    ASSERT_EQ(result, 20);
}


TEST(forEachTest, forEachEmptyVector) {
    // Function passed to forEach() should never be called if vector is empty.
    forEach(vector<int> {}, [](const int /*value*/) -> void { FAIL(); });
}


TEST(forEachTest, forEachMap) {
    vector<string> result;

    const map<string, const int> values {
        { "first"  , 3 },
        { "second" , 1 },
        { "third"  , 2 },
    };

    forEach(values, [&](const string & key, const int value) -> void {
        result.push_back(key + toString(value));
    });

    assertEqualElements(
        {
            "first3",
            "second1",
            "third2",
        },
        result);
}


TEST(forEachTest, forEachEmptyMap) {
    // Function passed to forEach() should never be called if map is empty.
    forEach(map<string, int> {}, [](const string & /*key*/, const int /*value*/) -> void { FAIL(); });
}


} // namespace CppUtils
