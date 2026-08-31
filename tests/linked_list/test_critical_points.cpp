#include <gtest/gtest.h>
#include "linked_list/critical_points.hpp"

namespace {
std::vector<int> criticalPointsOf(const std::vector<int>& values) {
    ListNode* head = buildList(values);
    std::vector<int> result = nodesBetweenCriticalPoints(head);
    freeList(head);
    return result;
}
}  // namespace

TEST(NodesBetweenCriticalPoints, BasicExamples) {
    EXPECT_EQ(criticalPointsOf({3, 1}), (std::vector<int>{-1, -1}));
    EXPECT_EQ(criticalPointsOf({5, 3, 1, 2, 5, 1, 2}), (std::vector<int>{1, 3}));
    EXPECT_EQ(criticalPointsOf({1, 3, 2, 2, 3, 2, 2, 2, 7}), (std::vector<int>{3, 3}));
}

TEST(NodesBetweenCriticalPoints, SingleCriticalPointHasNoPair) {
    // One peak on its own leaves no distance to measure.
    EXPECT_EQ(criticalPointsOf({1, 2, 1}), (std::vector<int>{-1, -1}));
}

TEST(NodesBetweenCriticalPoints, MonotonicListsHaveNone) {
    EXPECT_EQ(criticalPointsOf({1, 2, 3, 4, 5}), (std::vector<int>{-1, -1}));
    EXPECT_EQ(criticalPointsOf({5, 4, 3, 2, 1}), (std::vector<int>{-1, -1}));
}

TEST(NodesBetweenCriticalPoints, PlateausAreNotCritical) {
    // A node equal to a neighbour is neither strictly larger nor smaller than
    // both sides, so flat stretches never count.
    EXPECT_EQ(criticalPointsOf({2, 3, 3, 2}), (std::vector<int>{-1, -1}));
    EXPECT_EQ(criticalPointsOf({2, 2, 2, 2, 2}), (std::vector<int>{-1, -1}));
}

TEST(NodesBetweenCriticalPoints, AlternatingValues) {
    // Every interior node alternates between peak and valley, so neighbouring
    // critical points sit one apart and the outermost pair spans the rest.
    EXPECT_EQ(criticalPointsOf({1, 3, 1, 3, 1}), (std::vector<int>{1, 2}));
    EXPECT_EQ(criticalPointsOf({1, 5, 1, 9, 1, 9, 1}), (std::vector<int>{1, 4}));
}

TEST(NodesBetweenCriticalPoints, ClosestPairIsNotTheOutermostOne) {
    EXPECT_EQ(criticalPointsOf({6, 8, 4, 1, 9, 6, 1, 7, 2, 7}), (std::vector<int>{1, 7}));
}

TEST(NodesBetweenCriticalPoints, EndsAreNeverCritical) {
    // The head and tail have only one neighbour each: both 9s stand above
    // everything around them but neither counts, so the answer covers only the
    // three interior turns instead of spanning the whole list.
    EXPECT_EQ(criticalPointsOf({9, 1, 5, 1, 9}), (std::vector<int>{1, 2}));
}
