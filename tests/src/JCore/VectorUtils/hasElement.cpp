#include "JCore/VectorUtils/hasElement.hpp"

#include <gtest/gtest.h>


using std::vector;


namespace JCore {


TEST(hasElementTest, validVector) {
    static const vector<int> validVector { 1, 2, 3, 4 };

    ASSERT_TRUE(hasElement(validVector, 1));
    ASSERT_FALSE(hasElement(validVector, 5));
}


TEST(hasElementTest, emptyVector) {
    static const vector<int> emptyVector;

    ASSERT_FALSE(hasElement(emptyVector, 1));
}


} // namespace JCore
