#include <gtest/gtest.h>
#include "arrays/min_sum_of_lengths.hpp"

// Example 1: the only subarrays summing to 3 are [3] at index 0 and [3] at
// index 4, so 1 + 1 = 2.
TEST(MinSumOfLengths, BasicExample) {
    std::vector<int> arr = {3, 2, 2, 4, 3};
    EXPECT_EQ(minSumOfLengths(arr, 3), 2);
}

// Example 2: [7], [3,4] and [7] all sum to 7; the two single elements at the
// ends are non-overlapping, giving 1 + 1 = 2.
TEST(MinSumOfLengths, PrefersShortestPair) {
    std::vector<int> arr = {7, 3, 4, 7};
    EXPECT_EQ(minSumOfLengths(arr, 7), 2);
}

// Example 3: [6] at index 3 is the only subarray summing to 6, so no second
// one exists.
TEST(MinSumOfLengths, OnlyOneSubarrayExists) {
    std::vector<int> arr = {4, 3, 2, 6, 2, 3, 4};
    EXPECT_EQ(minSumOfLengths(arr, 6), -1);
}

// Example 4: every element is 4 or 5, so no subarray sums to 3 at all.
TEST(MinSumOfLengths, NoSubarrayReachesTarget) {
    std::vector<int> arr = {5, 5, 4, 4, 5};
    EXPECT_EQ(minSumOfLengths(arr, 3), -1);
}

// Example 5: candidates are [3] (len 1), [1,1,1] (len 3), [1,2] and [2,1]
// (len 2). The best non-overlapping pair is [3] + [1,2] = 1 + 2 = 3.
TEST(MinSumOfLengths, PicksBestNonOverlappingPair) {
    std::vector<int> arr = {3, 1, 1, 1, 5, 1, 2, 1};
    EXPECT_EQ(minSumOfLengths(arr, 3), 3);
}

// One element can supply at most one subarray, never two.
TEST(MinSumOfLengths, SingleElement) {
    std::vector<int> arr = {3};
    EXPECT_EQ(minSumOfLengths(arr, 3), -1);
}

// [2,2] occurs at indices 0-1, 1-2 and 2-3; the disjoint pair 0-1 and 2-3
// gives 2 + 2 = 4.
TEST(MinSumOfLengths, AllSameElements) {
    std::vector<int> arr = {2, 2, 2, 2};
    EXPECT_EQ(minSumOfLengths(arr, 4), 4);
}
