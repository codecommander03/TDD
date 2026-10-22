#include <gtest/gtest.h>
#include "arrays/min_operations_to_sort_permutation.hpp"

// LeetCode Example 1: rotate -> [2,1,0], reverse -> [0,1,2]
TEST(MinOperationsToSortPermutation, Example1) {
    std::vector<int> nums = {0, 2, 1};
    EXPECT_EQ(minOperations(nums), 2);
}

// LeetCode Example 2: reverse -> [2,0,1], rotate -> [0,1,2]
TEST(MinOperationsToSortPermutation, Example2) {
    std::vector<int> nums = {1, 0, 2};
    EXPECT_EQ(minOperations(nums), 2);
}

// LeetCode Example 3: not a rotation of sorted or reverse-sorted -> -1
TEST(MinOperationsToSortPermutation, Example3) {
    std::vector<int> nums = {2, 0, 1, 3};
    EXPECT_EQ(minOperations(nums), -1);
}

// Single element is already sorted
TEST(MinOperationsToSortPermutation, SingleElement) {
    std::vector<int> nums = {0};
    EXPECT_EQ(minOperations(nums), 0);
}

// Already sorted
TEST(MinOperationsToSortPermutation, AlreadySorted) {
    std::vector<int> nums = {0, 1, 2, 3};
    EXPECT_EQ(minOperations(nums), 0);
}

// Fully reversed: one reverse
TEST(MinOperationsToSortPermutation, FullyReversed) {
    std::vector<int> nums = {3, 2, 1, 0};
    EXPECT_EQ(minOperations(nums), 1);
}

// [1,2,3,0]: none of the four 2-op sequences sorts it; three left rotations
// (or reverse, rotate, reverse) do -> 3
TEST(MinOperationsToSortPermutation, NeedsThreeOps) {
    std::vector<int> nums = {1, 2, 3, 0};
    EXPECT_EQ(minOperations(nums), 3);
}
