#include <gtest/gtest.h>
#include "arrays/max_k_to_sort_permutation.hpp"

// LeetCode Example 1: swap 3 and 1, 3 AND 1 = 1
TEST(MaxKToSortPermutation, Example1) {
    std::vector<int> nums = {0, 3, 2, 1};
    EXPECT_EQ(sortPermutation(nums), 1);
}

// LeetCode Example 2: swap 3 and 2, 3 AND 2 = 2
TEST(MaxKToSortPermutation, Example2) {
    std::vector<int> nums = {0, 1, 3, 2};
    EXPECT_EQ(sortPermutation(nums), 2);
}

// LeetCode Example 3: only k = 0 permits sorting
TEST(MaxKToSortPermutation, Example3) {
    std::vector<int> nums = {3, 2, 1, 0};
    EXPECT_EQ(sortPermutation(nums), 0);
}

// Single element is already sorted -> 0
TEST(MaxKToSortPermutation, SingleElement) {
    std::vector<int> nums = {0};
    EXPECT_EQ(sortPermutation(nums), 0);
}

// Already sorted -> 0
TEST(MaxKToSortPermutation, AlreadySorted) {
    std::vector<int> nums = {0, 1, 2};
    EXPECT_EQ(sortPermutation(nums), 0);
}

// Only 7 and 6 are misplaced and must swap: 7 AND 6 = 6
TEST(MaxKToSortPermutation, LargerAndValue) {
    std::vector<int> nums = {0, 1, 2, 3, 4, 5, 7, 6};
    EXPECT_EQ(sortPermutation(nums), 6);
}
