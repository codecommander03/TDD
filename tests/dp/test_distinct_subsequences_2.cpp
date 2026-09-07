#include <gtest/gtest.h>
#include "dp/distinct_subsequences_2.hpp"

TEST(DistinctSubsequencesII, Example1) {
    // Example 1: "abc" has 7 distinct subsequences --
    // "a", "b", "c", "ab", "ac", "bc", "abc".
    EXPECT_EQ(distinctSubseqII("abc"), 7);
}

TEST(DistinctSubsequencesII, Example2) {
    // Example 2: "aba" has 6 -- "a", "b", "ab", "aa", "ba", "aba".
    // ("a" is counted once even though it can be picked from two positions.)
    EXPECT_EQ(distinctSubseqII("aba"), 6);
}

TEST(DistinctSubsequencesII, Example3) {
    // Example 3: "aaa" has 3 -- "a", "aa", "aaa".
    EXPECT_EQ(distinctSubseqII("aaa"), 3);
}

TEST(DistinctSubsequencesII, SingleCharacter) {
    // One character yields exactly one non-empty subsequence: itself.
    EXPECT_EQ(distinctSubseqII("a"), 1);
}

TEST(DistinctSubsequencesII, RepeatThenNew) {
    // "aab": "a", "b", "aa", "ab", "aab" -- 5. The second 'a' adds only "aa"
    // and the longer strings built on it, never a duplicate "a".
    EXPECT_EQ(distinctSubseqII("aab"), 5);
}

TEST(DistinctSubsequencesII, AllDistinctFourChars) {
    // Four distinct characters: every non-empty subset of positions spells a
    // different string, so 2^4 - 1 = 15.
    EXPECT_EQ(distinctSubseqII("abcd"), 15);
}

TEST(DistinctSubsequencesII, Empty) {
    // No characters, so no non-empty subsequences.
    EXPECT_EQ(distinctSubseqII(""), 0);
}
