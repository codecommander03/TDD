#include <gtest/gtest.h>
#include "segment_tree/subarrays_distinct_element_sum_of_squares_ii.hpp"

TEST(SubarraysDistinctElementSumOfSquaresII, Example1) {
    // Example 1: [1],[2],[1] -> 1 each; [1,2],[2,1],[1,2,1] -> 2^2 each.
    // 3 + 12 = 15.
    std::vector<int> nums = {1, 2, 1};
    EXPECT_EQ(sumCountsII(nums), 15);
}

TEST(SubarraysDistinctElementSumOfSquaresII, Example2) {
    // Example 2: [1],[1],[1,1] each have 1 distinct value -> 3.
    std::vector<int> nums = {1, 1};
    EXPECT_EQ(sumCountsII(nums), 3);
}

TEST(SubarraysDistinctElementSumOfSquaresII, SingleElement) {
    std::vector<int> nums = {5};
    EXPECT_EQ(sumCountsII(nums), 1);
}

TEST(SubarraysDistinctElementSumOfSquaresII, AllSame) {
    // 6 subarrays, each with 1 distinct value -> 6.
    std::vector<int> nums = {7, 7, 7};
    EXPECT_EQ(sumCountsII(nums), 6);
}

TEST(SubarraysDistinctElementSumOfSquaresII, AllDistinct) {
    // Length 1: 3 * 1, length 2: 2 * 4, length 3: 1 * 9 -> 3 + 8 + 9 = 20.
    std::vector<int> nums = {1, 2, 3};
    EXPECT_EQ(sumCountsII(nums), 20);
}

TEST(SubarraysDistinctElementSumOfSquaresII, Alternating) {
    // Length 1: 4 * 1; length 2: [1,2],[2,1],[1,2] -> 3 * 4;
    // length 3: 2 * 4; length 4: 1 * 4 -> 4 + 12 + 8 + 4 = 28.
    std::vector<int> nums = {1, 2, 1, 2};
    EXPECT_EQ(sumCountsII(nums), 28);
}

TEST(SubarraysDistinctElementSumOfSquaresII, LargeAllSameWrapsModulo) {
    // n = 1e5 copies: n(n+1)/2 = 5000050000 subarrays, each 1^2.
    // 5000050000 - 5 * (1e9 + 7) = 49965.
    std::vector<int> nums(100000, 1);
    EXPECT_EQ(sumCountsII(nums), 49965);
}

TEST(SubarraysDistinctElementSumOfSquaresII, LargeAllDistinctWrapsModulo) {
    // All distinct: sum over L of (n - L + 1) * L^2 = n(n+1)^2(n+2) / 12.
    // For n = 1e5 that is 83335833358333350000 -> 497683716 mod 1e9 + 7.
    std::vector<int> nums(100000);
    for (int i = 0; i < 100000; i++) nums[i] = i + 1;
    EXPECT_EQ(sumCountsII(nums), 497683716);
}
