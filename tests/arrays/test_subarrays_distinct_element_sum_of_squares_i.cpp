#include <gtest/gtest.h>
#include "arrays/subarrays_distinct_element_sum_of_squares_i.hpp"

TEST(SubarraysDistinctElementSumOfSquaresI, Example1) {
    // Example 1: [1],[2],[1] -> 1 each; [1,2],[2,1],[1,2,1] -> 2^2 each.
    // 3 + 12 = 15.
    std::vector<int> nums = {1, 2, 1};
    EXPECT_EQ(sumCounts(nums), 15);
}

TEST(SubarraysDistinctElementSumOfSquaresI, Example2) {
    // Example 2: [1],[1],[1,1] each have 1 distinct value -> 3.
    std::vector<int> nums = {1, 1};
    EXPECT_EQ(sumCounts(nums), 3);
}

TEST(SubarraysDistinctElementSumOfSquaresI, SingleElement) {
    std::vector<int> nums = {5};
    EXPECT_EQ(sumCounts(nums), 1);
}

TEST(SubarraysDistinctElementSumOfSquaresI, AllSame) {
    // 6 subarrays, each with 1 distinct value -> 6.
    std::vector<int> nums = {7, 7, 7};
    EXPECT_EQ(sumCounts(nums), 6);
}

TEST(SubarraysDistinctElementSumOfSquaresI, AllDistinct) {
    // Length 1: 3 * 1, length 2: 2 * 4, length 3: 1 * 9 -> 3 + 8 + 9 = 20.
    std::vector<int> nums = {1, 2, 3};
    EXPECT_EQ(sumCounts(nums), 20);
}
