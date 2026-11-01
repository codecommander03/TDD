#include <gtest/gtest.h>
#include "arrays/minimum_moves_to_equal_array_elements.hpp"

// LeetCode Example 1: [1,2,3] -> [2,3,3] -> [3,4,3] -> [4,4,4] -> 3
TEST(MinimumMovesToEqualArrayElements, Example1) {
    std::vector<int> nums = {1, 2, 3};
    EXPECT_EQ(minMoves(nums), 3);
}

// LeetCode Example 2: already equal -> 0
TEST(MinimumMovesToEqualArrayElements, Example2) {
    std::vector<int> nums = {1, 1, 1};
    EXPECT_EQ(minMoves(nums), 0);
}

// Single element is trivially equal -> 0
TEST(MinimumMovesToEqualArrayElements, SingleElement) {
    std::vector<int> nums = {5};
    EXPECT_EQ(minMoves(nums), 0);
}

// [1,3]: each move raises only the 1, gap of 2 -> 2
TEST(MinimumMovesToEqualArrayElements, TwoElements) {
    std::vector<int> nums = {1, 3};
    EXPECT_EQ(minMoves(nums), 2);
}

// Negatives: [-1,1] has a gap of 2 -> 2
TEST(MinimumMovesToEqualArrayElements, Negatives) {
    std::vector<int> nums = {-1, 1};
    EXPECT_EQ(minMoves(nums), 2);
}

// Unsorted with duplicates: min 5, distances 0+1+3+3+0 -> 7
TEST(MinimumMovesToEqualArrayElements, UnsortedWithDuplicates) {
    std::vector<int> nums = {5, 6, 8, 8, 5};
    EXPECT_EQ(minMoves(nums), 7);
}
