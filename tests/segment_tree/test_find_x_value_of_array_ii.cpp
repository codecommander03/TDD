#include <gtest/gtest.h>
#include "segment_tree/find_x_value_of_array_ii.hpp"

TEST(FindXValueOfArrayII, Example1) {
    // Statement example 1, k = 3.
    // [2,2,0,2]: nums becomes [1,2,2,4,5]; prefixes from 0 are 1,2,4,16,80,
    //            i.e. 1,2,1,1,2 mod 3 -> two land on 2.
    // [3,3,3,0]: nums becomes [1,2,2,3,5]; prefixes from 3 are 3 and 15,
    //            both 0 mod 3 -> 2.
    // [0,1,0,1]: nums[0] is already 1; prefixes from 0 are 1,2,4,12,60,
    //            i.e. 1,2,1,0,0 mod 3 -> two land on 1.
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<std::vector<int>> queries = {{2, 2, 0, 2}, {3, 3, 3, 0}, {0, 1, 0, 1}};
    EXPECT_EQ(resultArray(nums, 3, queries), (std::vector<int>{2, 2, 2}));
}

TEST(FindXValueOfArrayII, Example2) {
    // Statement example 2, k = 4. Both queries set nums[0] = 2, giving
    // [2,2,4,8,16,32]; the prefixes from 0 are 2,0,0,0,0,0 mod 4, so one
    // equals 2 and none equals 1.
    std::vector<int> nums = {1, 2, 4, 8, 16, 32};
    std::vector<std::vector<int>> queries = {{0, 2, 0, 2}, {0, 2, 0, 1}};
    EXPECT_EQ(resultArray(nums, 4, queries), (std::vector<int>{1, 0}));
}

TEST(FindXValueOfArrayII, UpdatesPersistAcrossQueries) {
    // k = 3. First query sets nums[0] = 2 -> [2,2,3]; prefixes 2,4,12 are
    // 2,1,0 mod 3, so one equals 2.
    // Second query sets nums[1] = 4 and keeps nums[0] = 2 -> [2,4,3];
    // prefixes 2,8,24 are 2,2,0 mod 3, so two equal 2. (Without the first
    // update persisting it would be [1,4,3] -> 1,1,0 and the answer 0.)
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> queries = {{0, 2, 0, 2}, {1, 4, 0, 2}};
    EXPECT_EQ(resultArray(nums, 3, queries), (std::vector<int>{1, 2}));
}

TEST(FindXValueOfArrayII, SingleElement) {
    // The array becomes [4] and its only prefix is 4, which is 0 mod 2.
    std::vector<int> nums = {3};
    std::vector<std::vector<int>> queries = {{0, 4, 0, 0}};
    EXPECT_EQ(resultArray(nums, 2, queries), (std::vector<int>{1}));
}

TEST(FindXValueOfArrayII, StartAtLastIndex) {
    // k = 5, nums becomes [2,5,4]; starting at index 2 leaves the single
    // prefix 4, which is 4 mod 5.
    std::vector<int> nums = {2, 3, 4};
    std::vector<std::vector<int>> queries = {{1, 5, 2, 4}};
    EXPECT_EQ(resultArray(nums, 5, queries), (std::vector<int>{1}));
}

TEST(FindXValueOfArrayII, ModuloOne) {
    // Every product is 0 modulo 1, so both prefixes of [5,9] count.
    std::vector<int> nums = {5, 7};
    std::vector<std::vector<int>> queries = {{1, 9, 0, 0}};
    EXPECT_EQ(resultArray(nums, 1, queries), (std::vector<int>{2}));
}
