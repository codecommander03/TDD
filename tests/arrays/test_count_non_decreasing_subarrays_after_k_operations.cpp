#include <gtest/gtest.h>
#include "arrays/count_non_decreasing_subarrays_after_k_operations.hpp"

// LeetCode Example 1: 21 subarrays; only those starting [6,3,1] fail
// (costs 3 + 5 = 8, then 12, 14, 16, all > 7) -> 21 - 4 = 17
TEST(CountNonDecreasingSubarraysAfterKOperations, Example1) {
    std::vector<int> nums = {6, 3, 1, 2, 4, 4};
    EXPECT_EQ(countNonDecreasingSubarrays(nums, 7), 17);
}

// LeetCode Example 2: 15 subarrays; [6,3,1] (8), [6,3,1,3] (11) and
// [6,3,1,3,6] (11) exceed 4 -> 15 - 3 = 12
TEST(CountNonDecreasingSubarraysAfterKOperations, Example2) {
    std::vector<int> nums = {6, 3, 1, 3, 6};
    EXPECT_EQ(countNonDecreasingSubarrays(nums, 4), 12);
}

// Single element is always non-decreasing -> 1
TEST(CountNonDecreasingSubarraysAfterKOperations, SingleElement) {
    std::vector<int> nums = {5};
    EXPECT_EQ(countNonDecreasingSubarrays(nums, 0), 1);
}

// Already increasing, k = 0: all 3 * 4 / 2 = 6 subarrays
TEST(CountNonDecreasingSubarraysAfterKOperations, AlreadySorted) {
    std::vector<int> nums = {1, 2, 3};
    EXPECT_EQ(countNonDecreasingSubarrays(nums, 0), 6);
}

// All equal counts as non-decreasing, k = 0 -> 6
TEST(CountNonDecreasingSubarraysAfterKOperations, AllSame) {
    std::vector<int> nums = {2, 2, 2};
    EXPECT_EQ(countNonDecreasingSubarrays(nums, 0), 6);
}

// Decreasing, k = 0: only the 3 single elements
TEST(CountNonDecreasingSubarraysAfterKOperations, DecreasingNoOps) {
    std::vector<int> nums = {3, 2, 1};
    EXPECT_EQ(countNonDecreasingSubarrays(nums, 0), 3);
}

// Decreasing, k = 1: singles (3) + [3,2] and [2,1] (cost 1 each);
// [3,2,1] costs 1 + 2 = 3 -> 5
TEST(CountNonDecreasingSubarraysAfterKOperations, DecreasingOneOp) {
    std::vector<int> nums = {3, 2, 1};
    EXPECT_EQ(countNonDecreasingSubarrays(nums, 1), 5);
}
