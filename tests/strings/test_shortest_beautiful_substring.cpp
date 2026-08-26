#include <gtest/gtest.h>
#include "strings/shortest_beautiful_substring.hpp"

TEST(ShortestBeautifulSubstring, PicksShortestWindow) {
    // The two 3-one windows are "100011" and "11001"; the second is shorter.
    EXPECT_EQ(shortestBeautifulSubstring("100011001", 3), "11001");
}

TEST(ShortestBeautifulSubstring, ShortestWindowWithoutTies) {
    // "101" also holds two ones, but "11" is shorter.
    EXPECT_EQ(shortestBeautifulSubstring("1011", 2), "11");
    EXPECT_EQ(shortestBeautifulSubstring("11", 2), "11");
}

TEST(ShortestBeautifulSubstring, SingleOneRequested) {
    // With k == 1 every '1' is its own beautiful substring.
    EXPECT_EQ(shortestBeautifulSubstring("000", 1), "");
    EXPECT_EQ(shortestBeautifulSubstring("0001000", 1), "1");
}

TEST(ShortestBeautifulSubstring, NotEnoughOnes) {
    // Only two ones in the string, so no window ever holds three.
    EXPECT_EQ(shortestBeautifulSubstring("1010", 3), "");
    EXPECT_EQ(shortestBeautifulSubstring("0", 1), "");
}

TEST(ShortestBeautifulSubstring, WholeStringIsTheOnlyWindow) {
    // Every character is needed, so the answer is s itself.
    EXPECT_EQ(shortestBeautifulSubstring("10101", 3), "10101");
}

TEST(ShortestBeautifulSubstring, LeadingAndTrailingZerosAreTrimmed) {
    // The zeros outside the first and last '1' never belong to the answer.
    EXPECT_EQ(shortestBeautifulSubstring("000110000", 2), "11");
}

TEST(ShortestBeautifulSubstring, BreaksLengthTiesLexicographically) {
    // "110011" holds two windows of length 5: "11001" and "10011". The zeros
    // sit earlier in the second, so it is the lexicographically smaller answer.
    EXPECT_EQ(shortestBeautifulSubstring("110011", 3), "10011");
}

TEST(ShortestBeautifulSubstring, AllOnes) {
    // Ones everywhere: the answer is k of them and nothing else.
    EXPECT_EQ(shortestBeautifulSubstring("11111", 4), "1111");
    EXPECT_EQ(shortestBeautifulSubstring("11111", 5), "11111");
}
