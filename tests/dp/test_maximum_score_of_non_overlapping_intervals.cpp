#include <gtest/gtest.h>
#include "dp/maximum_score_of_non_overlapping_intervals.hpp"

TEST(MaximumScoreOfNonOverlappingIntervals, Example1) {
    // Example 1: [1,5] (weight 5) and [6,9] (weight 3) total 8. The best
    // three-interval run, [1,3] + [4,5] + [6,9], is only 2 + 2 + 3 = 7.
    std::vector<std::vector<int>> intervals = {
        {1, 3, 2}, {4, 5, 2}, {1, 5, 5}, {6, 9, 3}, {6, 7, 1}, {8, 9, 1}};
    EXPECT_EQ(maximumWeight(intervals), (std::vector<int>{2, 3}));
}

TEST(MaximumScoreOfNonOverlappingIntervals, Example2) {
    // Example 2: [3,5] + [6,7] + [9,10] + [11,14] are disjoint and weigh
    // 5 + 7 + 6 + 3 = 21, the most four intervals can reach here.
    std::vector<std::vector<int>> intervals = {{5, 8, 1}, {6, 7, 7},  {4, 7, 3}, {9, 10, 6},
                                               {7, 8, 2}, {11, 14, 3}, {3, 5, 5}};
    EXPECT_EQ(maximumWeight(intervals), (std::vector<int>{1, 3, 5, 6}));
}

TEST(MaximumScoreOfNonOverlappingIntervals, SingleInterval) {
    // Nothing to conflict with, so the lone interval is taken.
    std::vector<std::vector<int>> intervals = {{1, 2, 5}};
    EXPECT_EQ(maximumWeight(intervals), (std::vector<int>{0}));
}

TEST(MaximumScoreOfNonOverlappingIntervals, CapsAtFourIntervals) {
    // Five disjoint unit intervals but only four may be chosen, so the
    // lightest one (index 0, weight 1) is dropped.
    std::vector<std::vector<int>> intervals = {
        {1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}, {5, 5, 5}};
    EXPECT_EQ(maximumWeight(intervals), (std::vector<int>{1, 2, 3, 4}));
}

TEST(MaximumScoreOfNonOverlappingIntervals, TiedWeightsPickSmallestIndex) {
    // The two intervals overlap and weigh the same, so only one fits and the
    // lexicographically smaller choice wins.
    std::vector<std::vector<int>> intervals = {{1, 5, 4}, {1, 5, 4}};
    EXPECT_EQ(maximumWeight(intervals), (std::vector<int>{0}));
}

TEST(MaximumScoreOfNonOverlappingIntervals, TieBreakInsideALargerSet) {
    // Either of the weight-2 intervals pairs with [3,4] for a total of 3;
    // {0, 2} sorts ahead of {1, 2}.
    std::vector<std::vector<int>> intervals = {{1, 2, 2}, {1, 2, 2}, {3, 4, 1}};
    EXPECT_EQ(maximumWeight(intervals), (std::vector<int>{0, 2}));
}
