#include <gtest/gtest.h>
#include "dp/distinct_subsequences.hpp"

TEST(DistinctSubsequences, Example1) {
    // Example 1: "rabbbit" -> "rabbit" in 3 ways, one per choice of which of
    // the three b's is dropped.
    EXPECT_EQ(numDistinct("rabbbit", "rabbit"), 3);
}

TEST(DistinctSubsequences, Example2) {
    // Example 2: "babgbag" -> "bag" in 5 ways. Indexing b-a-b-g-b-a-g as
    // 0..6, the picks are (0,1,3), (0,1,6), (0,5,6), (2,5,6) and (4,5,6).
    EXPECT_EQ(numDistinct("babgbag", "bag"), 5);
}

TEST(DistinctSubsequences, EmptyTarget) {
    // The empty target is spelled exactly one way: choose no characters.
    EXPECT_EQ(numDistinct("abc", ""), 1);
    EXPECT_EQ(numDistinct("", ""), 1);
}

TEST(DistinctSubsequences, TargetLongerThanSource) {
    // Nothing to draw from, or too few characters to draw -> no subsequence.
    EXPECT_EQ(numDistinct("", "a"), 0);
    EXPECT_EQ(numDistinct("ab", "abc"), 0);
}

TEST(DistinctSubsequences, NoMatch) {
    // "d" never appears in "abc".
    EXPECT_EQ(numDistinct("abc", "d"), 0);
}

TEST(DistinctSubsequences, IdenticalStrings) {
    // Every character must be taken, so there is exactly one way.
    EXPECT_EQ(numDistinct("abc", "abc"), 1);
}

TEST(DistinctSubsequences, RepeatedCharacters) {
    // From "aaa": one 'a' can be picked 3 ways, two of them C(3,2) = 3 ways,
    // all three exactly 1 way.
    EXPECT_EQ(numDistinct("aaa", "a"), 3);
    EXPECT_EQ(numDistinct("aaa", "aa"), 3);
    EXPECT_EQ(numDistinct("aaa", "aaa"), 1);
}
