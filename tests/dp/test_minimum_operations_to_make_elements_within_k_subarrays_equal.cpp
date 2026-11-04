#include <gtest/gtest.h>
#include "dp/minimum_operations_to_make_elements_within_k_subarrays_equal.hpp"

// LeetCode Example 1: [-2,1,3] -> all 1 costs 3 + 0 + 2 = 5,
// [3,6,4] -> all 4 costs 1 + 2 + 0 = 3, total 8
TEST(MinimumOperationsToMakeElementsWithinKSubarraysEqual, Example1) {
    std::vector<int> nums = {5, -2, 1, 3, 7, 3, 6, 4, -1};
    EXPECT_EQ(minOperations(nums, 3, 2), 8);
}

// LeetCode Example 2: [-2,-2] costs 0, [-2,1] costs 3, total 3
TEST(MinimumOperationsToMakeElementsWithinKSubarraysEqual, Example2) {
    std::vector<int> nums = {9, -2, -2, -2, 1, 5};
    EXPECT_EQ(minOperations(nums, 2, 2), 3);
}

// x = 1: a single element is already equal to itself -> 0
TEST(MinimumOperationsToMakeElementsWithinKSubarraysEqual, WindowSizeOne) {
    std::vector<int> nums = {3, 1, 4};
    EXPECT_EQ(minOperations(nums, 1, 2), 0);
}

// All same -> 0
TEST(MinimumOperationsToMakeElementsWithinKSubarraysEqual, AllSame) {
    std::vector<int> nums = {7, 7, 7, 7};
    EXPECT_EQ(minOperations(nums, 2, 2), 0);
}

// One even-sized window covering everything: [1,2,3,4] -> all 2 costs
// 1 + 0 + 1 + 2 = 4
TEST(MinimumOperationsToMakeElementsWithinKSubarraysEqual, WholeArrayEvenWindow) {
    std::vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(minOperations(nums, 4, 1), 4);
}

// Windows tile the array exactly: [1,3] costs 2, [2,2] costs 0 -> 2
TEST(MinimumOperationsToMakeElementsWithinKSubarraysEqual, WindowsTileArray) {
    std::vector<int> nums = {1, 3, 2, 2};
    EXPECT_EQ(minOperations(nums, 2, 2), 2);
}

// Every window of size 2 is [1,10] or [10,1] -> 9
TEST(MinimumOperationsToMakeElementsWithinKSubarraysEqual, AlternatingValues) {
    std::vector<int> nums = {1, 10, 1, 10};
    EXPECT_EQ(minOperations(nums, 2, 1), 9);
}
