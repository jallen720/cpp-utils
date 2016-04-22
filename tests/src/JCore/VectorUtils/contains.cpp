#include "JCore/VectorUtils/contains.hpp"

#include <gtest/gtest.h>


using std::vector;


namespace JCore {


TEST(containsTest, validVectorContainsElement) {
    static const vector<int> validVector { 1, 2, 3, 4 };

    ASSERT_TRUE(contains(validVector, 1));
    ASSERT_FALSE(contains(validVector, 5));
}


TEST(containsTest, emptyVectorContainsElement) {
    static const vector<int> emptyVector;

    ASSERT_FALSE(contains(emptyVector, 1));
}


TEST(containsTest, validVectorContainsPredicate) {
    static const vector<int> validVector { 1, 2, 3, 4 };

    ASSERT_TRUE(contains(validVector, [](int element) { return element < 3; }));
    ASSERT_TRUE(contains(validVector, [](int element) { return element == 4; }));
    ASSERT_FALSE(contains(validVector, [](int element) { return element > 4; }));
    ASSERT_FALSE(contains(validVector, [](int element) { return element < 1; }));
}


TEST(containsTest, emptyVectorContainsPredicate) {
    static const vector<int> emptyVector;

    ASSERT_FALSE(contains(emptyVector, [](int element) { return element >= 1; }));
    ASSERT_FALSE(contains(emptyVector, [](int element) { return element == 0; }));
}


} // namespace JCore
