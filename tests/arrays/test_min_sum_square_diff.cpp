#include <gtest/gtest.h>
#include "arrays/min_sum_square_diff.hpp"

TEST(MinSumSquareDiff, Example1) {
    // Example 1: no changes allowed; diffs 1, 8, 17, 15
    // -> 1 + 64 + 289 + 225 = 579.
    std::vector<int> nums1 = {1, 2, 3, 4};
    std::vector<int> nums2 = {2, 10, 20, 19};
    EXPECT_EQ(minSumSquareDiff(nums1, nums2, 0, 0), 579);
}

TEST(MinSumSquareDiff, Example2) {
    // Example 2: diffs 4, 4, 4, 3 with 2 changes -> 3, 3, 4, 3
    // -> 9 + 9 + 16 + 9 = 43.
    std::vector<int> nums1 = {1, 4, 10, 12};
    std::vector<int> nums2 = {5, 8, 6, 9};
    EXPECT_EQ(minSumSquareDiff(nums1, nums2, 1, 1), 43);
}

TEST(MinSumSquareDiff, EnoughChangesToZeroAll) {
    // Diffs 1, 2 need 3 changes total; 5 available -> 0.
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {2, 4};
    EXPECT_EQ(minSumSquareDiff(nums1, nums2, 5, 0), 0);
}

TEST(MinSumSquareDiff, SingleEqualElement) {
    // Diff is already 0 -> 0.
    std::vector<int> nums1 = {5};
    std::vector<int> nums2 = {5};
    EXPECT_EQ(minSumSquareDiff(nums1, nums2, 0, 0), 0);
}

TEST(MinSumSquareDiff, ChangesFromBothArrays) {
    // Diff 10, k1 + k2 = 3 + 4 = 7 -> 3, squared 9.
    std::vector<int> nums1 = {10};
    std::vector<int> nums2 = {0};
    EXPECT_EQ(minSumSquareDiff(nums1, nums2, 3, 4), 9);
}

TEST(MinSumSquareDiff, SpreadChangesEvenly) {
    // Diffs 5, 5, 5 with 3 changes -> 4, 4, 4 (48), beating 5, 5, 2 (54).
    std::vector<int> nums1 = {5, 5, 5};
    std::vector<int> nums2 = {0, 0, 0};
    EXPECT_EQ(minSumSquareDiff(nums1, nums2, 3, 0), 48);
}
