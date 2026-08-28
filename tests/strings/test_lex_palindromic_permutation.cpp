#include <gtest/gtest.h>
#include "strings/lex_palindromic_permutation.hpp"

TEST(LexPalindromicPermutation, KeepsTargetsHalfWhenTheMirrorIsEnough) {
    // The half "ab" is spelled exactly, and the mirrored tail "ba" already
    // beats target's own tail "ab".
    EXPECT_EQ(lexPalindromicPermutation("aabb", "abab"), "abba");
}

TEST(LexPalindromicPermutation, RisesWhenTheMirrorFallsShort) {
    // "abba" is spelled exactly but is not strictly greater, so the half has to
    // rise, and only its first position can.
    EXPECT_EQ(lexPalindromicPermutation("aabb", "abba"), "baab");
}

TEST(LexPalindromicPermutation, RisesWhereTargetsHalfCannotBeSpelled) {
    // s has no 'c', so the half stops matching at index 1 and the rise happens
    // back at index 0.
    EXPECT_EQ(lexPalindromicPermutation("aabb", "acca"), "baab");
}

TEST(LexPalindromicPermutation, KeepsTheLongestPossiblePrefix) {
    // Target is spelled exactly, so the rise moves as deep as it can: index 1
    // keeps "a" in front, which beats every half that rises at index 0.
    EXPECT_EQ(lexPalindromicPermutation("aabbcc", "abccba"), "acbbca");
}

TEST(LexPalindromicPermutation, RisesImmediatelyWhenTargetIsSmall) {
    EXPECT_EQ(lexPalindromicPermutation("aabb", "aaaa"), "abba");
    EXPECT_EQ(lexPalindromicPermutation("aabbc", "aaaaa"), "abcba");
}

TEST(LexPalindromicPermutation, OddLengthPlacesTheLoneLetterInTheMiddle) {
    // 'b' is the only letter with an odd count, so it is pinned to the middle
    // and the halves are built from the pairs of 'a'.
    EXPECT_EQ(lexPalindromicPermutation("aba", "aab"), "aba");
    EXPECT_EQ(lexPalindromicPermutation("aabbb", "abbba"), "babab");
}

TEST(LexPalindromicPermutation, MiddleLetterDecidesTheComparison) {
    // The half "ab" matches target, so the answer turns on the middle letter:
    // "abcba" rises above "ababa" at the centre.
    EXPECT_EQ(lexPalindromicPermutation("aabbc", "ababa"), "abcba");
}

TEST(LexPalindromicPermutation, NoPalindromeIsLargeEnough) {
    // "cbaabc" is the largest palindrome s can spell and it only ties target.
    EXPECT_EQ(lexPalindromicPermutation("aabbcc", "cbaabc"), "");
    EXPECT_EQ(lexPalindromicPermutation("aab", "aba"), "");
    EXPECT_EQ(lexPalindromicPermutation("aab", "bbb"), "");
}

TEST(LexPalindromicPermutation, TwoOddCountsCannotFormAPalindrome) {
    // 'b' and 'c' both appear once, and only one letter can sit in the middle.
    EXPECT_EQ(lexPalindromicPermutation("aabc", "aaaa"), "");
}

TEST(LexPalindromicPermutation, SingleCharacter) {
    EXPECT_EQ(lexPalindromicPermutation("b", "a"), "b");
    EXPECT_EQ(lexPalindromicPermutation("a", "b"), "");
    EXPECT_EQ(lexPalindromicPermutation("a", "a"), "");
}

TEST(LexPalindromicPermutation, RepeatedLetterHasNothingToRiseTo) {
    // Every permutation of s is target itself.
    EXPECT_EQ(lexPalindromicPermutation("aaaa", "aaaa"), "");
}

TEST(LexPalindromicPermutation, SmallestRiseIsChosen) {
    // Index 0 can rise to either 'b' or 'c'; 'b' is the smaller rise, and the
    // leftovers behind it are laid out sorted.
    EXPECT_EQ(lexPalindromicPermutation("aabbcc", "bbbbbb"), "bcaacb");
}

TEST(LexPalindromicPermutation, LettersFarApartInTheAlphabet) {
    EXPECT_EQ(lexPalindromicPermutation("zzaa", "azza"), "zaaz");
}
