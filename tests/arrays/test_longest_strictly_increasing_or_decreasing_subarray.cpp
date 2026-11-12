#include <gtest/gtest.h>
#include "arrays/longest_strictly_increasing_or_decreasing_subarray.hpp"

// LeetCode Example 1: longest runs are [1,4] and [4,3] / [3,2] -> 2
TEST(LongestStrictlyIncreasingOrDecreasingSubarray, Example1) {
    std::vector<int> nums = {1, 4, 3, 3, 2};
    EXPECT_EQ(longestMonotonicSubarray(nums), 2);
}

// LeetCode Example 2: all equal, no strict pair -> 1
TEST(LongestStrictlyIncreasingOrDecreasingSubarray, Example2) {
    std::vector<int> nums = {3, 3, 3, 3};
    EXPECT_EQ(longestMonotonicSubarray(nums), 1);
}

// LeetCode Example 3: the whole array decreases -> 3
TEST(LongestStrictlyIncreasingOrDecreasingSubarray, Example3) {
    std::vector<int> nums = {3, 2, 1};
    EXPECT_EQ(longestMonotonicSubarray(nums), 3);
}

// Single element -> 1
TEST(LongestStrictlyIncreasingOrDecreasingSubarray, SingleElement) {
    std::vector<int> nums = {5};
    EXPECT_EQ(longestMonotonicSubarray(nums), 1);
}

// Up 1,2,3 then down 3,2,1,0,-1: the decreasing run of 5 wins
TEST(LongestStrictlyIncreasingOrDecreasingSubarray, PeakThenLongerDescent) {
    std::vector<int> nums = {1, 2, 3, 2, 1, 0, -1};
    EXPECT_EQ(longestMonotonicSubarray(nums), 5);
}

// A plateau breaks the run: [1,2] then [2,3,4] -> 3
TEST(LongestStrictlyIncreasingOrDecreasingSubarray, PlateauBreaksRun) {
    std::vector<int> nums = {1, 2, 2, 3, 4};
    EXPECT_EQ(longestMonotonicSubarray(nums), 3);
}
