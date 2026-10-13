#include <gtest/gtest.h>
#include "arrays/max_alternating_sum_of_squares.hpp"

TEST(MaxAlternatingSumOfSquares, Example1) {
    // Example 1: two added slots, one subtracted -> 9 + 4 - 1 = 12.
    std::vector<int> nums = {1, 2, 3};
    EXPECT_EQ(maxAlternatingSum(nums), 12);
}

TEST(MaxAlternatingSumOfSquares, Example2) {
    // Example 2: squares 1,1,4,4,9,9; add 9+9+4, subtract 1+1+4 -> 22 - 6 = 16.
    std::vector<int> nums = {1, -1, 2, -2, 3, -3};
    EXPECT_EQ(maxAlternatingSum(nums), 16);
}

TEST(MaxAlternatingSumOfSquares, SingleElement) {
    // Only index 0, which is added -> 25.
    std::vector<int> nums = {5};
    EXPECT_EQ(maxAlternatingSum(nums), 25);
}

TEST(MaxAlternatingSumOfSquares, AllSame) {
    // 4 + 4 - 4 - 4 = 0.
    std::vector<int> nums = {2, 2, 2, 2};
    EXPECT_EQ(maxAlternatingSum(nums), 0);
}

TEST(MaxAlternatingSumOfSquares, NegativeHasLargestSquare) {
    // -4 has the larger square, so it goes in the added slot: 16 - 1 = 15.
    std::vector<int> nums = {1, -4};
    EXPECT_EQ(maxAlternatingSum(nums), 15);
}

TEST(MaxAlternatingSumOfSquares, LargeValues) {
    // Three 40000s: 1.6e9 + 1.6e9 - 1.6e9 = 1.6e9; the two added squares alone total 3.2e9 > INT_MAX.
    std::vector<int> nums = {40000, 40000, 40000};
    EXPECT_EQ(maxAlternatingSum(nums), 1600000000LL);
}
