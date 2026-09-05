#include <gtest/gtest.h>
#include "arrays/smallest_stable_index_ii.hpp"

TEST(SmallestStableIndexII, Example1) {
    // Statement example: prefix maxes 5,5,5,5 and suffix mins 0,0,1,4 give
    // scores 5,5,4,1; index 3 is the first with score <= 3.
    std::vector<int> nums = {5, 0, 1, 4};
    EXPECT_EQ(firstStableIndexII(nums, 3), 3);
}

TEST(SmallestStableIndexII, Example2) {
    // Statement example: prefix max is 3 and suffix min is 1 at every index,
    // so every score is 2 and none is <= 1.
    std::vector<int> nums = {3, 2, 1};
    EXPECT_EQ(firstStableIndexII(nums, 1), -1);
}

TEST(SmallestStableIndexII, Example3) {
    // Statement example: the lone index scores 0 - 0 = 0.
    std::vector<int> nums = {0};
    EXPECT_EQ(firstStableIndexII(nums, 0), 0);
}

TEST(SmallestStableIndexII, FirstStableIsInTheMiddle) {
    // Hand-traced: prefix maxes 6,6,7,7 and suffix mins 1,1,7,7 give scores
    // 5,5,0,0; index 2 is the first within k = 1.
    std::vector<int> nums = {6, 1, 7, 7};
    EXPECT_EQ(firstStableIndexII(nums, 1), 2);
}

TEST(SmallestStableIndexII, ZeroKRejectsEverything) {
    // Same array as Example1; the smallest score is 1, so no index is stable.
    std::vector<int> nums = {5, 0, 1, 4};
    EXPECT_EQ(firstStableIndexII(nums, 0), -1);
}

TEST(SmallestStableIndexII, SortedAscendingIsStableAtZero) {
    // Prefix max and suffix min both equal nums[i] at every index, so index 0
    // already scores 1 - 1 = 0.
    std::vector<int> nums = {1, 2, 3};
    EXPECT_EQ(firstStableIndexII(nums, 0), 0);
}

TEST(SmallestStableIndexII, AllEqual) {
    // Every prefix max and suffix min is 7, so index 0 already scores 0.
    std::vector<int> nums = {7, 7, 7};
    EXPECT_EQ(firstStableIndexII(nums, 0), 0);
}

TEST(SmallestStableIndexII, LastIndexOnly) {
    // Scores: 4-1=3, 4-1=3, 4-4=0. Only index 2 is within k = 0.
    std::vector<int> nums = {4, 1, 4};
    EXPECT_EQ(firstStableIndexII(nums, 0), 2);
}

TEST(SmallestStableIndexII, ExtremeValuesAtConstraintBound) {
    // Constraints allow nums[i] and k up to 1e9: scores are 1e9 - 0 = 1e9 at
    // both indices, exactly equal to k, so index 0 is stable.
    std::vector<int> nums = {1000000000, 0};
    EXPECT_EQ(firstStableIndexII(nums, 1000000000), 0);
    EXPECT_EQ(firstStableIndexII(nums, 999999999), -1);
}
