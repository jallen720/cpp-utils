#include "Cpp_Utils/Type.hpp"

#include <gtest/gtest.h>


namespace Cpp_Utils
{


TEST(type_of_Test, equal_types)
{
    ASSERT_EQ(type_of<int>(), type_of<int>());
    ASSERT_EQ(type_of<int &>(), type_of<int>());
    ASSERT_NE(type_of<float>(), type_of<int>());
    ASSERT_NE(type_of<int *>(), type_of<int>());
}


TEST(type_of_Test, types_with_cv_qualifiers)
{
    ASSERT_EQ(type_of<const int>(), type_of<int>());
    ASSERT_EQ(type_of<const int &>(), type_of<int>());
    ASSERT_EQ(type_of<int * const>(), type_of<int *>());
    ASSERT_EQ(type_of<const int *>(), type_of<const int *>());
    ASSERT_EQ(type_of<const int * const>(), type_of<const int *>());
}


} // namespace Cpp_Utils
