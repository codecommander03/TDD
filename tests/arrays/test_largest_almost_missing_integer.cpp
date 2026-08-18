#include <gtest/gtest.h>
#include "arrays/largest_almost_missing_integer.hpp"

TEST(LargestAlmostMissingInteger, Example1) {
    // Example 1: 3 and 7 each appear in exactly one size-3 window; 7 is larger.
    std::vector<int> nums = {3, 9, 2, 1, 7};
    EXPECT_EQ(largestInteger(nums, 3), 7);
}

TEST(LargestAlmostMissingInteger, Example2) {
    // Example 2: k=4 -> the answer is 3.
    std::vector<int> nums = {3, 9, 7, 2, 1, 7};
    EXPECT_EQ(largestInteger(nums, 4), 3);
}

TEST(LargestAlmostMissingInteger, NoneAlmostMissing) {
    // k=1: each element is its own window, so a value qualifies only if it
    // occurs exactly once. Both 0s occur twice -> -1.
    std::vector<int> nums = {0, 0};
    EXPECT_EQ(largestInteger(nums, 1), -1);
}

TEST(LargestAlmostMissingInteger, UnitWindowsUniqueValue) {
    // k=1: 5 occurs twice (excluded), 3 occurs once -> 3.
    std::vector<int> nums = {5, 3, 5};
    EXPECT_EQ(largestInteger(nums, 1), 3);
}
