#include <gtest/gtest.h>
#include "arrays/minimum_moves_to_equal_array_elements_2.hpp"

// LeetCode Example 1: [1,2,3] -> [2,2,3] -> [2,2,2] -> 2
TEST(MinimumMovesToEqualArrayElementsII, Example1) {
    std::vector<int> nums = {1, 2, 3};
    EXPECT_EQ(minMoves2(nums), 2);
}

// LeetCode Example 2: [1,10,2,9] -> 16
TEST(MinimumMovesToEqualArrayElementsII, Example2) {
    std::vector<int> nums = {1, 10, 2, 9};
    EXPECT_EQ(minMoves2(nums), 16);
}

// Single element is trivially equal -> 0
TEST(MinimumMovesToEqualArrayElementsII, SingleElement) {
    std::vector<int> nums = {5};
    EXPECT_EQ(minMoves2(nums), 0);
}

// All same -> 0
TEST(MinimumMovesToEqualArrayElementsII, AllSame) {
    std::vector<int> nums = {3, 3, 3};
    EXPECT_EQ(minMoves2(nums), 0);
}

// Negatives: [-5,0,5], meet at 0 -> 5 + 0 + 5 = 10
TEST(MinimumMovesToEqualArrayElementsII, Negatives) {
    std::vector<int> nums = {-5, 0, 5};
    EXPECT_EQ(minMoves2(nums), 10);
}

// Unsorted with duplicates: [7,1,4,4,10], meet at 4 -> 3 + 3 + 0 + 0 + 6 = 12
TEST(MinimumMovesToEqualArrayElementsII, UnsortedWithDuplicates) {
    std::vector<int> nums = {7, 1, 4, 4, 10};
    EXPECT_EQ(minMoves2(nums), 12);
}
