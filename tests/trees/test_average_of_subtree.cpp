#include <gtest/gtest.h>
#include "trees/average_of_subtree.hpp"

namespace {
int averageOfSubtreeOf(const std::vector<std::optional<int>>& values) {
    TreeNode* root = buildTree(values);
    int result = averageOfSubtree(root);
    freeTree(root);
    return result;
}
}  // namespace

TEST(AverageOfSubtree, BasicExamples) {
    // Example 1: the three leaves 0, 1 and 6 always match themselves, node 5
    // holds {5, 6} averaging 11 / 2 = 5, and the root holds all six values
    // averaging 24 / 6 = 4; only node 8 misses, with {8, 0, 1} averaging 3.
    EXPECT_EQ(averageOfSubtreeOf({4, 8, 5, 0, 1, std::nullopt, 6}), 5);

    // Example 2: a lone node is its own average.
    EXPECT_EQ(averageOfSubtreeOf({1}), 1);
}

TEST(AverageOfSubtree, LeavesAlwaysCount) {
    // Every leaf's subtree is the leaf itself, so all three of these match and
    // the root's {2, 4} averages 6 / 2 = 3, which is not 2.
    EXPECT_EQ(averageOfSubtreeOf({2, 4}), 1);
    EXPECT_EQ(averageOfSubtreeOf({7}), 1);
}

TEST(AverageOfSubtree, AllSameValueMatchesEverywhere) {
    // Any subtree of equal values averages to that value.
    EXPECT_EQ(averageOfSubtreeOf({5, 5, 5}), 3);
}

TEST(AverageOfSubtree, AverageRoundsDown) {
    // The root holds {2, 3, 2}: 7 / 3 is 2.33, which rounds down to 2 and so
    // matches the root, joining the two leaves for 3 in total.
    EXPECT_EQ(averageOfSubtreeOf({2, 3, 2}), 3);
}

TEST(AverageOfSubtree, SkewedChain) {
    // 3 -> 2 -> 1 down the left spine: only the leaf 1 matches, since {2, 1}
    // averages 3 / 2 = 1 and {3, 2, 1} averages 6 / 3 = 2.
    EXPECT_EQ(averageOfSubtreeOf({3, 2, std::nullopt, 1}), 1);
}

TEST(AverageOfSubtree, EmptyTreeHasNoNodes) {
    EXPECT_EQ(averageOfSubtreeOf({}), 0);
}
