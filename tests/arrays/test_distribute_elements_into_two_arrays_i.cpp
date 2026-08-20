#include <gtest/gtest.h>
#include "arrays/distribute_elements_into_two_arrays_i.hpp"

TEST(DistributeElementsIntoTwoArraysI, Example1) {
    std::vector<int> nums = {2, 1, 3};
    EXPECT_EQ(resultArray(nums), (std::vector<int>{2, 3, 1}));
}

TEST(DistributeElementsIntoTwoArraysI, Example2) {
    std::vector<int> nums = {5, 4, 3, 8};
    EXPECT_EQ(resultArray(nums), (std::vector<int>{5, 3, 4, 8}));
}

TEST(DistributeElementsIntoTwoArraysI, TwoElements) {
    // Only the two seeding operations happen.
    std::vector<int> nums = {1, 2};
    EXPECT_EQ(resultArray(nums), (std::vector<int>{1, 2}));
}

TEST(DistributeElementsIntoTwoArraysI, IncreasingGoesToSecondArray) {
    // arr1 tail stays 1, so every later element lands in arr2.
    std::vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(resultArray(nums), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(DistributeElementsIntoTwoArraysI, Decreasing) {
    // 3 -> arr1, 2 -> arr2 (3 < 4), then 1 -> arr1 (3 > 2).
    std::vector<int> nums = {5, 4, 3, 2, 1};
    EXPECT_EQ(resultArray(nums), (std::vector<int>{5, 3, 1, 4, 2}));
}
