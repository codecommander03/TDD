#include <gtest/gtest.h>
#include "arrays/min_operations_to_reduce_x_to_zero.hpp"

// Example 1: removing the last two elements subtracts 3 then 2, taking x from
// 5 to 0.
TEST(MinOperationsToReduceXToZero, Example1) {
    std::vector<int> nums = {1, 1, 4, 2, 3};
    EXPECT_EQ(minOperations(nums, 5), 2);
}

// Example 2: the smallest element is 5, so x = 4 can never be reduced to
// exactly 0.
TEST(MinOperationsToReduceXToZero, Example2Impossible) {
    std::vector<int> nums = {5, 6, 7, 8, 9};
    EXPECT_EQ(minOperations(nums, 4), -1);
}

// Example 3: 3 + 2 from the left and 3 + 1 + 1 from the right sum to 10, which
// is 5 operations; only the 20 in the middle is left.
TEST(MinOperationsToReduceXToZero, Example3) {
    std::vector<int> nums = {3, 2, 20, 1, 1, 3};
    EXPECT_EQ(minOperations(nums, 10), 5);
}

// x equals the whole sum, so every element has to go.
TEST(MinOperationsToReduceXToZero, RemovesEntireArray) {
    std::vector<int> nums = {1, 2, 3};
    EXPECT_EQ(minOperations(nums, 6), 3);
}

// The array totals 3, which is short of x no matter what is removed.
TEST(MinOperationsToReduceXToZero, TotalSmallerThanX) {
    std::vector<int> nums = {1, 2};
    EXPECT_EQ(minOperations(nums, 10), -1);
}

// A single element is either exactly x, or unusable.
TEST(MinOperationsToReduceXToZero, SingleElement) {
    std::vector<int> nums = {5};
    EXPECT_EQ(minOperations(nums, 5), 1);

    std::vector<int> other = {5};
    EXPECT_EQ(minOperations(other, 3), -1);
}

// Either 1 alone covers x, so one operation is enough.
TEST(MinOperationsToReduceXToZero, SingleOperationSuffices) {
    std::vector<int> nums = {1, 1};
    EXPECT_EQ(minOperations(nums, 1), 1);
}
