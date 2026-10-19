#include <gtest/gtest.h>
#include "arrays/find_target_indices.hpp"

// LeetCode Example 1: sorted [1,2,2,3,5], 2 sits at indices 1 and 2
TEST(FindTargetIndices, Example1) {
    std::vector<int> nums = {1, 2, 5, 2, 3};
    EXPECT_EQ(targetIndices(nums, 2), (std::vector<int>{1, 2}));
}

// LeetCode Example 2: sorted [1,2,2,3,5], 3 sits at index 3
TEST(FindTargetIndices, Example2) {
    std::vector<int> nums = {1, 2, 5, 2, 3};
    EXPECT_EQ(targetIndices(nums, 3), (std::vector<int>{3}));
}

// LeetCode Example 3: sorted [1,2,2,3,5], 5 sits at index 4
TEST(FindTargetIndices, Example3) {
    std::vector<int> nums = {1, 2, 5, 2, 3};
    EXPECT_EQ(targetIndices(nums, 5), (std::vector<int>{4}));
}

// Target absent: no indices
TEST(FindTargetIndices, TargetNotPresent) {
    std::vector<int> nums = {4, 1, 3};
    EXPECT_TRUE(targetIndices(nums, 2).empty());
}

// Single matching element: index 0
TEST(FindTargetIndices, SingleElement) {
    std::vector<int> nums = {7};
    EXPECT_EQ(targetIndices(nums, 7), (std::vector<int>{0}));
}

// All same and equal to target: every index
TEST(FindTargetIndices, AllSame) {
    std::vector<int> nums = {3, 3, 3};
    EXPECT_EQ(targetIndices(nums, 3), (std::vector<int>{0, 1, 2}));
}
