#include <gtest/gtest.h>
#include "math/num_ways_to_reorder_bst.hpp"

// Each count is n! / (product of subtree sizes) orderings, minus the original.

TEST(NumWaysToReorderBst, Example1) {
    // Example 1: root 2 with leaves 1 and 3 -> 3! / 3 = 2 orderings -> 1 other.
    std::vector<int> nums = {2, 1, 3};
    EXPECT_EQ(numOfWays(nums), 1);
}

TEST(NumWaysToReorderBst, Example2) {
    // Example 2: sizes 5 (root 3), 2 (1 -> 2), 2 (4 -> 5), 1, 1.
    // 120 / 20 = 6 -> 5 others.
    std::vector<int> nums = {3, 4, 5, 1, 2};
    EXPECT_EQ(numOfWays(nums), 5);
}

TEST(NumWaysToReorderBst, Example3) {
    // Example 3: chain 1 -> 2 -> 3, sizes 3, 2, 1 -> 6 / 6 = 1 -> 0 others.
    std::vector<int> nums = {1, 2, 3};
    EXPECT_EQ(numOfWays(nums), 0);
}

TEST(NumWaysToReorderBst, SingleElement) {
    // Only one ordering exists, so there are no others.
    std::vector<int> nums = {1};
    EXPECT_EQ(numOfWays(nums), 0);
}

TEST(NumWaysToReorderBst, TwoSubtreesOfThree) {
    // Root 3, left 1 -> 2, right 5 with leaves 4 and 6.
    // Sizes 6, 2, 1, 3, 1, 1 -> 720 / 36 = 20 -> 19 others.
    std::vector<int> nums = {3, 1, 2, 5, 4, 6};
    EXPECT_EQ(numOfWays(nums), 19);
}

TEST(NumWaysToReorderBst, LargeWrapsModulo) {
    // 18 nodes; the count exceeds 1e9 + 7. Expected value checked with a
    // separate recursion: ways(T) = C(|L| + |R|, |L|) * ways(L) * ways(R).
    std::vector<int> nums = {9, 4, 2, 1, 3, 6, 5, 7, 8, 14, 11, 10, 12, 13, 16, 15, 17, 18};
    EXPECT_EQ(numOfWays(nums), 216212978);
}
