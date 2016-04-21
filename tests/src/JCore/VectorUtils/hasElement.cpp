#include "JCore/VectorUtils/hasElement.hpp"

#include <gtest/gtest.h>


using std::vector;


namespace JCore {


TEST(hasElementTest, validVector) {
    static const vector<int> validVector { 1, 2, 3, 4 };

    EXPECT_TRUE(hasElement(validVector, 1));
    EXPECT_FALSE(hasElement(validVector, 5));
}


TEST(hasElementTest, emptyVector) {
    static const vector<int> emptyVector;

    EXPECT_FALSE(hasElement(emptyVector, 1));
}


} // namespace JCore
