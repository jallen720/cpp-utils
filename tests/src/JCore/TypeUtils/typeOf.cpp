#include "JCore/TypeUtils/typeOf.hpp"

#include <gtest/gtest.h>


namespace JCore {


TEST(typeOfTest, equalTypes) {
    int a = 0;
    int b = 1;

    EXPECT_EQ(typeOf<int>() , typeOf<int>());
    EXPECT_EQ(typeOf(a)     , typeOf<int>());
    EXPECT_EQ(typeOf(a)     , typeOf(b));
}


} // namespace JCore
