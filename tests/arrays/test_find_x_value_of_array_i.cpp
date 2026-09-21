#include <gtest/gtest.h>
#include "arrays/find_x_value_of_array_i.hpp"

TEST(FindXValueOfArrayI, Example1) {
    // Statement example 1: residues mod 3 are [1,2,0,1,2]. Of the 15 subarrays,
    // the 9 that contain index 2 have product 0; [1] and [4] give 1; [1,2],
    // [2], [4,5] and [5] give 2.
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<long long> expected = {9, 2, 4};
    EXPECT_EQ(resultArray(nums, 3), expected);
}

TEST(FindXValueOfArrayI, Example2) {
    // Statement example 2: residues mod 4 are [1,2,0,0,0,0]. Only [1] gives 1
    // and only [1,2] and [2] give 2, so 18 of the 21 subarrays give 0.
    std::vector<int> nums = {1, 2, 4, 8, 16, 32};
    std::vector<long long> expected = {18, 1, 2, 0};
    EXPECT_EQ(resultArray(nums, 4), expected);
}

TEST(FindXValueOfArrayI, SingleElement) {
    // The only subarray is [7], and 7 % 5 == 2.
    std::vector<int> nums = {7};
    std::vector<long long> expected = {0, 0, 1, 0, 0};
    EXPECT_EQ(resultArray(nums, 5), expected);
}

TEST(FindXValueOfArrayI, ModuloOne) {
    // Every product is 0 modulo 1, so all 3 * 4 / 2 == 6 subarrays land on 0.
    std::vector<int> nums = {3, 5, 7};
    std::vector<long long> expected = {6};
    EXPECT_EQ(resultArray(nums, 1), expected);
}

TEST(FindXValueOfArrayI, EveryElementDivisibleByK) {
    // Residues mod 2 are [0,0], so all 3 subarrays have product 0.
    std::vector<int> nums = {2, 4};
    std::vector<long long> expected = {3, 0};
    EXPECT_EQ(resultArray(nums, 2), expected);
}
