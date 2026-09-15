#include <gtest/gtest.h>
#include "strings/max_non_overlapping_palindromes.hpp"

TEST(MaxNonOverlappingPalindromes, Example1) {
    // Example 1: "aba" at 0 and "dbbd" at 5 are disjoint and both >= 3 long;
    // nothing starting at 3 or 4 is a palindrome of length 3 or 4.
    EXPECT_EQ(maxPalindromes("abaccdbbd", 3), 2);
}

TEST(MaxNonOverlappingPalindromes, Example2NoneQualify) {
    // Example 2: no substring of "adbcda" of length 2 or 3 is a palindrome.
    EXPECT_EQ(maxPalindromes("adbcda", 2), 0);
}

TEST(MaxNonOverlappingPalindromes, SingleCharactersAllCount) {
    // k == 1: every character is a palindrome on its own.
    EXPECT_EQ(maxPalindromes("abc", 1), 3);
    EXPECT_EQ(maxPalindromes("a", 1), 1);
}

TEST(MaxNonOverlappingPalindromes, WholeStringIsThePalindrome) {
    // k equals the length, and the whole string reads the same both ways.
    EXPECT_EQ(maxPalindromes("aba", 3), 1);
    // Not a palindrome, and no other window is long enough.
    EXPECT_EQ(maxPalindromes("abc", 3), 0);
}

TEST(MaxNonOverlappingPalindromes, EvenLengthNeedsTheKPlusOneCheck) {
    // "abba" has no palindrome of length 3, so only the length-4 window works.
    EXPECT_EQ(maxPalindromes("abba", 3), 1);
    // Likewise "aabaa" is a palindrome of length 5 with no length-4 one.
    EXPECT_EQ(maxPalindromes("aabaa", 4), 1);
}

TEST(MaxNonOverlappingPalindromes, RepeatedCharactersPackTightly) {
    // "aaaa" splits into "aa" + "aa"; a third pair would have to overlap.
    EXPECT_EQ(maxPalindromes("aaaa", 2), 2);
    EXPECT_EQ(maxPalindromes("aaaaa", 2), 2);
}
