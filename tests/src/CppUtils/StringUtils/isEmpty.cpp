#include "CppUtils/StringUtils/isEmpty.hpp"

#include <stdexcept>
#include <gtest/gtest.h>


using std::runtime_error;


namespace CppUtils {


TEST(isEmptyTest, validStrings) {
    ASSERT_TRUE(isEmpty(""));
    ASSERT_TRUE(isEmpty("\0"));
    ASSERT_FALSE(isEmpty("not empty"));
}


TEST(isEmptyTest, nullString) {
    ASSERT_THROW(isEmpty(nullptr), runtime_error);
}


} // namespace CppUtils
