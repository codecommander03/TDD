#include <gtest/gtest.h>
#include "math/smallest_index_with_digit_sum.hpp"

// Example 1: digit sums are 1, 3, 2; only index 2 matches its own digit sum.
TEST(SmallestIndexWithDigitSum, Example1) {
    std::vector<int> nums = {1, 3, 2};
    EXPECT_EQ(smallestIndex(nums), 2);
}

// Example 2: nums[1] = 10 has digit sum 1 + 0 = 1, matching index 1.
TEST(SmallestIndexWithDigitSum, Example2) {
    std::vector<int> nums = {1, 10, 11};
    EXPECT_EQ(smallestIndex(nums), 1);
}

// Example 3: digit sums are 1, 2, 3, each one ahead of its index.
TEST(SmallestIndexWithDigitSum, Example3NoMatch) {
    std::vector<int> nums = {1, 2, 3};
    EXPECT_EQ(smallestIndex(nums), -1);
}

// Digit sums are 7, 1, 2, 3: indices 1, 2 and 3 all match, and the smallest
// one wins.
TEST(SmallestIndexWithDigitSum, ReturnsSmallestOfSeveralMatches) {
    std::vector<int> nums = {7, 1, 20, 12};
    EXPECT_EQ(smallestIndex(nums), 1);
}

// 0 has digit sum 0, which matches index 0.
TEST(SmallestIndexWithDigitSum, ZeroAtIndexZero) {
    std::vector<int> nums = {0, 4, 4};
    EXPECT_EQ(smallestIndex(nums), 0);
}

// A single element whose digit sum is 5 cannot match index 0.
TEST(SmallestIndexWithDigitSum, SingleElementNoMatch) {
    std::vector<int> nums = {5};
    EXPECT_EQ(smallestIndex(nums), -1);
}

// 111 has digit sum 1 + 1 + 1 = 3, matching index 3.
TEST(SmallestIndexWithDigitSum, ThreeDigitElement) {
    std::vector<int> nums = {5, 5, 5, 111};
    EXPECT_EQ(smallestIndex(nums), 3);
}
