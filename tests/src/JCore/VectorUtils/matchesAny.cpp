#include "JCore/VectorUtils/matchesAny.hpp"

#include <gtest/gtest.h>


using std::vector;


namespace JCore {


TEST(matchesAnyTest, validVector) {
    static const vector<int> validVector { 1, 2, 3, 4 };

    ASSERT_TRUE(matchesAny(validVector, [](int element) { return element < 3; }));
    ASSERT_TRUE(matchesAny(validVector, [](int element) { return element == 4; }));
    ASSERT_FALSE(matchesAny(validVector, [](int element) { return element > 4; }));
    ASSERT_FALSE(matchesAny(validVector, [](int element) { return element < 1; }));
}


TEST(matchesAnyTest, emptyVector) {
    static const vector<int> emptyVector;

    ASSERT_FALSE(matchesAny(emptyVector, [](int element) { return element >= 1; }));
    ASSERT_FALSE(matchesAny(emptyVector, [](int element) { return element == 0; }));
}


} // namespace JCore
