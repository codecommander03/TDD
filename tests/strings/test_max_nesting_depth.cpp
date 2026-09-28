#include <gtest/gtest.h>
#include "strings/max_nesting_depth.hpp"

TEST(MaxNestingDepth, Example1) {
    // Example 1: the digit 8 sits inside three nested pairs.
    EXPECT_EQ(maxDepth("(1+(2*3)+((8)/4))+1"), 3);
}

TEST(MaxNestingDepth, Example2) {
    // Example 2: the digit 3 sits inside three nested pairs.
    EXPECT_EQ(maxDepth("(1)+((2))+(((3)))"), 3);
}

TEST(MaxNestingDepth, Example3) {
    // Example 3: the innermost "()" pairs in "((()()))" are three deep.
    EXPECT_EQ(maxDepth("()(())((()()))"), 3);
}

TEST(MaxNestingDepth, NoParentheses) {
    // A lone digit has no brackets at all, so the depth is 0.
    EXPECT_EQ(maxDepth("1"), 0);
}

TEST(MaxNestingDepth, EmptyString) {
    EXPECT_EQ(maxDepth(""), 0);
}

TEST(MaxNestingDepth, SiblingPairsDoNotAddUp) {
    // Three side-by-side pairs never nest, so the depth stays at 1.
    EXPECT_EQ(maxDepth("()()()"), 1);
}

TEST(MaxNestingDepth, DeepestGroupIsNotFirst) {
    // The first group reaches depth 1, the second reaches depth 2.
    EXPECT_EQ(maxDepth("(a)+((b))"), 2);
}
