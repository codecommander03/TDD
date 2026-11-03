#include <gtest/gtest.h>
#include "arrays/minimum_moves_to_equal_array_elements_3.hpp"

// LeetCode Example 1: [2,1,3], max 3 -> 1 + 2 + 0 = 3
TEST(MinimumMovesToEqualArrayElementsIII, Example1) {
    std::vector<int> nums = {2, 1, 3};
    EXPECT_EQ(minMoves(nums), 3);
}

// LeetCode Example 2: [4,4,5], max 5 -> 1 + 1 + 0 = 2
TEST(MinimumMovesToEqualArrayElementsIII, Example2) {
    std::vector<int> nums = {4, 4, 5};
    EXPECT_EQ(minMoves(nums), 2);
}

// Single element is trivially equal -> 0
TEST(MinimumMovesToEqualArrayElementsIII, SingleElement) {
    std::vector<int> nums = {7};
    EXPECT_EQ(minMoves(nums), 0);
}

// All same -> 0
TEST(MinimumMovesToEqualArrayElementsIII, AllSame) {
    std::vector<int> nums = {2, 2, 2};
    EXPECT_EQ(minMoves(nums), 0);
}

// Max first, unsorted: [10,1,5], max 10 -> 0 + 9 + 5 = 14
TEST(MinimumMovesToEqualArrayElementsIII, MaxFirstUnsorted) {
    std::vector<int> nums = {10, 1, 5};
    EXPECT_EQ(minMoves(nums), 14);
}
