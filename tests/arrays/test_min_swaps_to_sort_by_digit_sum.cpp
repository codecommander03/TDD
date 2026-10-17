#include <gtest/gtest.h>
#include "arrays/min_swaps_to_sort_by_digit_sum.hpp"

TEST(MinSwapsToSortByDigitSum, Example1) {
    // Example 1: digit sums 10, 1 -> target [100, 37]; one swap.
    std::vector<int> nums = {37, 100};
    EXPECT_EQ(minSwaps(nums), 1);
}

TEST(MinSwapsToSortByDigitSum, Example2) {
    // Example 2: digit sums 4, 5, 6, 7 are already ascending.
    std::vector<int> nums = {22, 14, 33, 7};
    EXPECT_EQ(minSwaps(nums), 0);
}

TEST(MinSwapsToSortByDigitSum, Example3) {
    // Example 3: digit sums 9, 7, 7, 7 -> target [16, 34, 43, 18].
    // Cycles (18 16) and (43 34) -> 2 swaps.
    std::vector<int> nums = {18, 43, 34, 16};
    EXPECT_EQ(minSwaps(nums), 2);
}

TEST(MinSwapsToSortByDigitSum, SingleElement) {
    std::vector<int> nums = {5};
    EXPECT_EQ(minSwaps(nums), 0);
}

TEST(MinSwapsToSortByDigitSum, SortedByDigitSumNotByValue) {
    // Digit sums 1, 2, 3 are already ascending, though the values are not.
    std::vector<int> nums = {100, 2, 30};
    EXPECT_EQ(minSwaps(nums), 0);
}

TEST(MinSwapsToSortByDigitSum, TieBreakThreeCycle) {
    // All digit sums are 3, so the target is by value: [3, 12, 30].
    // 30 -> idx 2, 12 -> idx 1, 3 -> idx 0: one 3-cycle -> 2 swaps.
    std::vector<int> nums = {30, 3, 12};
    EXPECT_EQ(minSwaps(nums), 2);
}
