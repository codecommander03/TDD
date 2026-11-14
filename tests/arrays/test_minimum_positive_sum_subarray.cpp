#include <gtest/gtest.h>
#include "arrays/minimum_positive_sum_subarray.hpp"

// Example 1: len-2 sums {1, -1, 5}, len-3 sums {2, 3} -> smallest positive is 1 ([3, -2]).
TEST(MinimumPositiveSumSubarray, Example1) {
    std::vector<int> nums = {3, -2, 1, 4};
    EXPECT_EQ(minimumSumSubarray(nums, 2, 3), 1);
}

// Example 2: len-2 sums {0, -1, -2}, len-3 sums {-3, 0} -> no positive sum.
TEST(MinimumPositiveSumSubarray, Example2NoPositiveSum) {
    std::vector<int> nums = {-2, 2, -3, 1};
    EXPECT_EQ(minimumSumSubarray(nums, 2, 3), -1);
}

// Example 3: smallest window is [1, 2] with sum 3.
TEST(MinimumPositiveSumSubarray, Example3) {
    std::vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(minimumSumSubarray(nums, 2, 4), 3);
}

// Single positive element, l = r = 1 -> the element itself.
TEST(MinimumPositiveSumSubarray, SinglePositiveElement) {
    std::vector<int> nums = {5};
    EXPECT_EQ(minimumSumSubarray(nums, 1, 1), 5);
}

// Single negative element -> no positive sum.
TEST(MinimumPositiveSumSubarray, SingleNegativeElement) {
    std::vector<int> nums = {-5};
    EXPECT_EQ(minimumSumSubarray(nums, 1, 1), -1);
}

// All-same: sums are 2, 4, 6 for lengths 1..3 -> 2.
TEST(MinimumPositiveSumSubarray, AllSame) {
    std::vector<int> nums = {2, 2, 2};
    EXPECT_EQ(minimumSumSubarray(nums, 1, 3), 2);
}

// Zero sum is not positive: only window [1, -1] sums to 0 -> -1.
TEST(MinimumPositiveSumSubarray, ZeroSumIsNotPositive) {
    std::vector<int> nums = {1, -1};
    EXPECT_EQ(minimumSumSubarray(nums, 2, 2), -1);
}
