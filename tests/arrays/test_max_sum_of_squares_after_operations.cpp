#include <gtest/gtest.h>
#include "arrays/max_sum_of_squares_after_operations.hpp"

TEST(MaxSumOfSquaresAfterOperations, Example1) {
    // Example 1: bit counts b0:1, b1:2, b2:2, b3:1, so the two best values
    // are 0b1111 = 15 and 0b0110 = 6 -> 225 + 36 = 261.
    std::vector<int> nums = {2, 6, 5, 8};
    EXPECT_EQ(maxSum(nums, 2), 261);
}

TEST(MaxSumOfSquaresAfterOperations, Example2) {
    // Example 2: no operations needed; pick 7, 5, 4 -> 49 + 25 + 16 = 90.
    std::vector<int> nums = {4, 5, 4, 7};
    EXPECT_EQ(maxSum(nums, 3), 90);
}

TEST(MaxSumOfSquaresAfterOperations, SingleElement) {
    // Only 3 to pick -> 9.
    std::vector<int> nums = {3};
    EXPECT_EQ(maxSum(nums, 1), 9);
}

TEST(MaxSumOfSquaresAfterOperations, MergeIntoOne) {
    // (1, 2) -> (1 AND 2, 1 OR 2) = (0, 3); pick 3 -> 9.
    std::vector<int> nums = {1, 2};
    EXPECT_EQ(maxSum(nums, 1), 9);
}

TEST(MaxSumOfSquaresAfterOperations, AllSame) {
    // Operations on equal values change nothing; 9 + 9 = 18.
    std::vector<int> nums = {3, 3};
    EXPECT_EQ(maxSum(nums, 2), 18);
}

TEST(MaxSumOfSquaresAfterOperations, TakesModulo) {
    // 1e9 = (1e9 + 7) - 7, so 1e9^2 = (-7)^2 = 49 mod 1e9 + 7.
    std::vector<int> nums = {1000000000};
    EXPECT_EQ(maxSum(nums, 1), 49);
}
