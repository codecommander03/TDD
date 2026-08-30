#include <gtest/gtest.h>
#include "arrays/removing_min_and_max.hpp"

TEST(RemovingMinAndMax, BasicExample) {
    // 1 sits at index 5 and 20 at index 7, so deleting the last four reaches
    // both and beats the eight it would take from the front.
    EXPECT_EQ(minimumDeletions({2, 10, 7, 5, 4, 1, 8, 20, 12}), 4);
    EXPECT_EQ(minimumDeletions({0, -4, 19, 1, 8, -2, -3, 5}), 3);
}

TEST(RemovingMinAndMax, BothEndsAreCheapest) {
    // Min at the front, max at the back: one deletion from each side.
    EXPECT_EQ(minimumDeletions({1, 5, 4, 3, 9}), 2);
    EXPECT_EQ(minimumDeletions({9, 5, 4, 3, 1}), 2);
}

TEST(RemovingMinAndMax, BothSitNearTheFront) {
    // Both targets are in the first two slots, so sweeping the front is best.
    EXPECT_EQ(minimumDeletions({7, 1, 3, 4, 5, 6}), 2);
    EXPECT_EQ(minimumDeletions({1, 7, 3, 4, 5, 6}), 2);
}

TEST(RemovingMinAndMax, BothSitNearTheBack) {
    EXPECT_EQ(minimumDeletions({3, 4, 5, 6, 7, 1}), 2);
    EXPECT_EQ(minimumDeletions({3, 4, 5, 6, 1, 7}), 2);
}

TEST(RemovingMinAndMax, MinAndMaxInTheMiddle) {
    // Indices 2 and 3 of six: four deletions either way, and splitting the work
    // across both ends would cost six.
    EXPECT_EQ(minimumDeletions({4, 5, 1, 9, 6, 7}), 4);
    // Here the split wins instead: min is second from the front, max second
    // from the back, so two deletions per side beat sweeping either way.
    EXPECT_EQ(minimumDeletions({3, 1, 4, 5, 9, 6}), 4);
}

TEST(RemovingMinAndMax, SingleElement) {
    // The lone element is both the minimum and the maximum.
    EXPECT_EQ(minimumDeletions({101}), 1);
}

TEST(RemovingMinAndMax, TwoElements) {
    EXPECT_EQ(minimumDeletions({2, 1}), 2);
    EXPECT_EQ(minimumDeletions({1, 2}), 2);
}

TEST(RemovingMinAndMax, SortedArrays) {
    // Sorted either way puts the extremes on the two ends.
    EXPECT_EQ(minimumDeletions({1, 2, 3, 4, 5, 6, 7, 8}), 2);
    EXPECT_EQ(minimumDeletions({8, 7, 6, 5, 4, 3, 2, 1}), 2);
}
