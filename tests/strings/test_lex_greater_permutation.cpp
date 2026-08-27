#include <gtest/gtest.h>
#include "strings/lex_greater_permutation.hpp"

TEST(LexGreaterPermutation, RisesAtTheLastPosition) {
    // "aa" is not reachable, and "ab" is the only other permutation.
    EXPECT_EQ(lexGreaterPermutation("ab", "aa"), "ab");
}

TEST(LexGreaterPermutation, EqualToTargetIsNotEnough) {
    // s spells target exactly, so the answer has to be the next permutation up.
    EXPECT_EQ(lexGreaterPermutation("abc", "abc"), "acb");
}

TEST(LexGreaterPermutation, BacktracksPastDeadEnds) {
    // "acb" is spelled exactly, and neither the last nor the middle position
    // can rise, so the rise happens at index 0 and the tail sorts itself.
    EXPECT_EQ(lexGreaterPermutation("abc", "acb"), "bac");
}

TEST(LexGreaterPermutation, KeepsTheLongestPossiblePrefix) {
    // "abab" is spelled exactly; rising at index 2 keeps "ab" in front, which
    // beats every permutation that rises earlier.
    EXPECT_EQ(lexGreaterPermutation("aabb", "abab"), "abba");
}

TEST(LexGreaterPermutation, RisesWhereTargetCannotBeMatched) {
    // s has no 'b', so the prefix stops at index 1 and 'c' takes that slot.
    EXPECT_EQ(lexGreaterPermutation("ac", "ab"), "ac");
}

TEST(LexGreaterPermutation, RisesImmediatelyWhenTargetIsSmall) {
    EXPECT_EQ(lexGreaterPermutation("bbb", "aaa"), "bbb");
}

TEST(LexGreaterPermutation, NoPermutationIsLargeEnough) {
    // "baa" is the largest permutation of s and it still trails target.
    EXPECT_EQ(lexGreaterPermutation("aab", "bbb"), "");
    EXPECT_EQ(lexGreaterPermutation("ab", "ba"), "");
}

TEST(LexGreaterPermutation, RepeatedLettersHaveNothingToRiseTo) {
    // Every permutation of s is target itself.
    EXPECT_EQ(lexGreaterPermutation("aaa", "aaa"), "");
}

TEST(LexGreaterPermutation, SingleCharacter) {
    EXPECT_EQ(lexGreaterPermutation("b", "a"), "b");
    EXPECT_EQ(lexGreaterPermutation("a", "b"), "");
    EXPECT_EQ(lexGreaterPermutation("a", "a"), "");
}

TEST(LexGreaterPermutation, RiseNearTheEndOfADistinctString) {
    // Only the middle position can rise, so "x" stays in front.
    EXPECT_EQ(lexGreaterPermutation("zyx", "xyz"), "xzy");
}

TEST(LexGreaterPermutation, SmallestRiseIsChosen) {
    // Index 0 has both 'b' and 'c' available; 'b' is the smaller rise.
    EXPECT_EQ(lexGreaterPermutation("cba", "acb"), "bac");
}
