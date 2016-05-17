#include "JCore/VectorUtils/contains.hpp"

#include <gtest/gtest.h>


using std::vector;


namespace JCore {


TEST(containsTest, validVectorContainsElement) {
    const vector<int> validVector { 1, 2, 3, 4 };

    ASSERT_TRUE(contains(validVector, 1));
    ASSERT_FALSE(contains(validVector, 5));
}


TEST(containsTest, emptyVectorContainsElement) {
    const vector<int> emptyVector;

    ASSERT_FALSE(contains(emptyVector, 1));
}


TEST(containsTest, validVectorContainsPredicate) {
    const vector<int> validVector { 1, 2, 3, 4 };

    ASSERT_TRUE(contains(validVector, [](const int element) -> bool { return element < 3; }));
    ASSERT_TRUE(contains(validVector, [](const int element) -> bool { return element == 4; }));
    ASSERT_FALSE(contains(validVector, [](const int element) -> bool { return element > 4; }));
    ASSERT_FALSE(contains(validVector, [](const int element) -> bool { return element < 1; }));
}


TEST(containsTest, emptyVectorContainsPredicate) {
    const vector<int> emptyVector;

    ASSERT_FALSE(contains(emptyVector, [](const int element) -> bool { return element >= 1; }));
    ASSERT_FALSE(contains(emptyVector, [](const int element) -> bool { return element == 0; }));
}


} // namespace JCore
