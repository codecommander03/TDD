#include <gtest/gtest.h>
#include "arrays/sum_of_sortable_integers.hpp"

// LeetCode Example 1: k=1 leaves [3,1,2] unsorted; k=3 rotates to [1,2,3] -> 3
TEST(SumOfSortableIntegers, Example1) {
    std::vector<int> nums = {3, 1, 2};
    EXPECT_EQ(sortableIntegers(nums), 3);
}

// LeetCode Example 2: no rotation of [7,6,5] is sorted, k=1 fails too -> 0
TEST(SumOfSortableIntegers, Example2) {
    std::vector<int> nums = {7, 6, 5};
    EXPECT_EQ(sortableIntegers(nums), 0);
}

// LeetCode Example 3: already sorted, k=1 and k=2 both work -> 1 + 2 = 3
TEST(SumOfSortableIntegers, Example3) {
    std::vector<int> nums = {5, 8};
    EXPECT_EQ(sortableIntegers(nums), 3);
}

// Single element: only k=1, trivially sorted -> 1
TEST(SumOfSortableIntegers, SingleElement) {
    std::vector<int> nums = {4};
    EXPECT_EQ(sortableIntegers(nums), 1);
}

// All same: every divisor of 4 works -> 1 + 2 + 4 = 7
TEST(SumOfSortableIntegers, AllSame) {
    std::vector<int> nums = {2, 2, 2, 2};
    EXPECT_EQ(sortableIntegers(nums), 7);
}

// k=2 rotates [2,1]->[1,2] and [4,3]->[3,4]; k=1 unsorted; no rotation of
// the whole array ([1,4,3,2], [4,3,2,1], [3,2,1,4]) is sorted -> 2
TEST(SumOfSortableIntegers, OnlyMiddleDivisorWorks) {
    std::vector<int> nums = {2, 1, 4, 3};
    EXPECT_EQ(sortableIntegers(nums), 2);
}
