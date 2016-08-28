#include "CppUtils/Fn/accumulate.hpp"

#include <vector>
#include <gtest/gtest.h>


using std::vector;


namespace CppUtils {


int accumulator(const int accumulation, const int number) {
    return accumulation + number;
}


TEST(accumulateTest, test) {
    const vector<int> numbers { 1, 2, 3 };
    const vector<int> empty;

    ASSERT_EQ(6, accumulate(0, numbers, accumulator));
    ASSERT_EQ(0, accumulate(0, empty, accumulator));
}


} // namespace CppUtils
