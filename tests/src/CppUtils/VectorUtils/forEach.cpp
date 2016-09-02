#include "CppUtils/VectorUtils/forEach.hpp"

#include <gtest/gtest.h>


using std::vector;


namespace CppUtils {


TEST(forEachTest, forEachOverValidVector) {
    int result = 0;
    const vector<int> values = { 1, 2, 3, 4 };
    const auto valueHandler = [&](const int value) -> void { result += value; };

    forEach(values, valueHandler);
    ASSERT_EQ(result, 10);
    forEach(values, valueHandler);
    ASSERT_EQ(result, 20);
}


TEST(forEachTest, forEachOverEmptyVector) {
    // Function passed to forEach() should never be called if vector is empty.
    forEach<int>({}, [](const int /*value*/) -> void { FAIL(); });
}


} // namespace CppUtils
