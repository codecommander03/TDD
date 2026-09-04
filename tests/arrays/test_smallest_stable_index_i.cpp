#include <gtest/gtest.h>
#include "arrays/smallest_stable_index_i.hpp"

TEST(SmallestStableIndexI, Example1) {
    // Statement example: scores are 5-0=5, 5-0=5, 5-1=4, 5-4=1;
    // index 3 is the first with score <= 3.
    std::vector<int> nums = {5, 0, 1, 4};
    EXPECT_EQ(firstStableIndex(nums, 3), 3);
}

TEST(SmallestStableIndexI, Example2) {
    // Statement example: prefix max is 3 and suffix min is 1 at every index,
    // so every score is 2 and none is <= 1.
    std::vector<int> nums = {3, 2, 1};
    EXPECT_EQ(firstStableIndex(nums, 1), -1);
}

TEST(SmallestStableIndexI, Example3) {
    // Statement example: the lone index scores 0 - 0 = 0.
    std::vector<int> nums = {0};
    EXPECT_EQ(firstStableIndex(nums, 0), 0);
}

TEST(SmallestStableIndexI, SortedAscendingIsStableAtZero) {
    // Prefix max and suffix min both equal nums[0] = 1 at index 0, score 0.
    std::vector<int> nums = {1, 2, 3};
    EXPECT_EQ(firstStableIndex(nums, 0), 0);
}

TEST(SmallestStableIndexI, AllEqual) {
    // Every prefix max and suffix min is 7, so index 0 already scores 0.
    std::vector<int> nums = {7, 7, 7};
    EXPECT_EQ(firstStableIndex(nums, 0), 0);
}

TEST(SmallestStableIndexI, LargeKAcceptsIndexZero) {
    // Same array as Example1; index 0 scores 5, which is now within k.
    std::vector<int> nums = {5, 0, 1, 4};
    EXPECT_EQ(firstStableIndex(nums, 100), 0);
}

TEST(SmallestStableIndexI, ZeroKRejectsEverything) {
    // Same array as Example1; the smallest score is 1, so no index is stable.
    std::vector<int> nums = {5, 0, 1, 4};
    EXPECT_EQ(firstStableIndex(nums, 0), -1);
}

TEST(SmallestStableIndexI, LastIndexOnly) {
    // Scores: 4-1=3, 4-1=3, 4-4=0. Only index 2 is within k = 0.
    std::vector<int> nums = {4, 1, 4};
    EXPECT_EQ(firstStableIndex(nums, 0), 2);
}
