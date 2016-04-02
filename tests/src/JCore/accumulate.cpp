#include "JCore/accumulate.hpp"

#include <vector>
#include <gtest/gtest.h>

using std::vector;

namespace JCore {

TEST(accumulateTest, test) {
    const vector<int> numbers { 1, 2, 3 };
    const vector<int> empty;

    const auto accumulator = [](const int accumulation, const int number) {
        return accumulation + number;
    };

    ASSERT_EQ(6, accumulate(0, numbers, accumulator));
    EXPECT_EQ(0, accumulate(0, empty, accumulator));
}

} // namespace JCore
