#include <gtest/gtest.h>
#include "arrays/lexicographically_smallest_array.hpp"

TEST(LexicographicallySmallestArray, BasicExample) {
    EXPECT_EQ(lexicographicallySmallestArray({1, 5, 3, 9, 8}, 2),
              (std::vector<int>{1, 3, 5, 8, 9}));
}

TEST(LexicographicallySmallestArray, GroupsKeepTheirOwnPositions) {
    // {1, 1, 2} and {6, 7} are separate groups, so 18 never moves and the two
    // groups only shuffle within the slots they already occupy.
    EXPECT_EQ(lexicographicallySmallestArray({1, 7, 6, 18, 2, 1}, 3),
              (std::vector<int>{1, 6, 7, 18, 1, 2}));
}

TEST(LexicographicallySmallestArray, NothingIsSwappable) {
    // Every neighbouring gap in sorted order exceeds limit, so each element is
    // its own group and the array cannot change.
    EXPECT_EQ(lexicographicallySmallestArray({1, 7, 28, 19, 10}, 3),
              (std::vector<int>{1, 7, 28, 19, 10}));
    EXPECT_EQ(lexicographicallySmallestArray({5, 3, 1}, 1),
              (std::vector<int>{5, 3, 1}));
}

TEST(LexicographicallySmallestArray, SwapsChainThroughMiddleValues) {
    // 7 and 1 differ by more than limit, but the steps 7-5, 5-3, 3-1 link them
    // into one group, so the whole array can be sorted.
    EXPECT_EQ(lexicographicallySmallestArray({7, 5, 3, 1}, 2),
              (std::vector<int>{1, 3, 5, 7}));
}

TEST(LexicographicallySmallestArray, LargeLimitSortsEverything) {
    EXPECT_EQ(lexicographicallySmallestArray({3, 1, 2}, 5),
              (std::vector<int>{1, 2, 3}));
}

TEST(LexicographicallySmallestArray, TwoGroupsInterleaved) {
    // {1, 2} sits at indices 1 and 3, {10, 11} at indices 0 and 2; each group
    // sorts itself across its own slots.
    EXPECT_EQ(lexicographicallySmallestArray({11, 2, 10, 1}, 1),
              (std::vector<int>{10, 1, 11, 2}));
    EXPECT_EQ(lexicographicallySmallestArray({9, 8, 7, 100, 99}, 1),
              (std::vector<int>{7, 8, 9, 99, 100}));
}

TEST(LexicographicallySmallestArray, EqualValuesSwapAtZeroLimit) {
    // The two 2s are swappable at limit 0 but 1 is on its own, so trading the
    // 2s changes nothing and the array stays put.
    EXPECT_EQ(lexicographicallySmallestArray({2, 2, 1}, 0),
              (std::vector<int>{2, 2, 1}));
    EXPECT_EQ(lexicographicallySmallestArray({4, 4, 4}, 1),
              (std::vector<int>{4, 4, 4}));
}

TEST(LexicographicallySmallestArray, SingleElement) {
    EXPECT_EQ(lexicographicallySmallestArray({5}, 1), (std::vector<int>{5}));
}
