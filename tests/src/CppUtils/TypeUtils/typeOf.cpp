#include "CppUtils/TypeUtils/typeOf.hpp"

#include <gtest/gtest.h>


namespace CppUtils
{


TEST(typeOfTest, equalTypes)
{
    ASSERT_EQ(typeOf<int>()   , typeOf<int>());
    ASSERT_EQ(typeOf<int&>()  , typeOf<int>());
    ASSERT_NE(typeOf<float>() , typeOf<int>());
    ASSERT_NE(typeOf<int*>()  , typeOf<int>());
}


TEST(typeOfTest, typesWithCVQualifiers)
{
    ASSERT_EQ(typeOf<const int>()        , typeOf<int>());
    ASSERT_EQ(typeOf<const int&>()       , typeOf<int>());
    ASSERT_EQ(typeOf<int* const>()       , typeOf<int*>());
    ASSERT_EQ(typeOf<const int*>()       , typeOf<const int*>());
    ASSERT_EQ(typeOf<const int* const>() , typeOf<const int*>());
}


} // namespace CppUtils
