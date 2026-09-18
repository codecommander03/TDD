#include <gtest/gtest.h>
#include "strings/max_num_of_substrings.hpp"

TEST(MaxNumOfSubstrings, Example1) {
    // "adefaddaccc": 'a' spans 0..7 and 'd' spans 1..6, so either one drags in
    // the other and costs the whole prefix. 'e', 'f' and the run of 'c's stand
    // alone, giving three substrings instead of two.
    EXPECT_EQ(maxNumOfSubstrings("adefaddaccc"),
              (std::vector<std::string>{"e", "f", "ccc"}));
}

TEST(MaxNumOfSubstrings, Example2) {
    // "abbaccd": 'a' spans 0..3 and holds both 'b's, so "abba" is valid but
    // blocks "bb". Taking "bb", "cc" and "d" gives three. (The statement lists
    // the same three in a different order.)
    EXPECT_EQ(maxNumOfSubstrings("abbaccd"),
              (std::vector<std::string>{"bb", "cc", "d"}));
}

TEST(MaxNumOfSubstrings, SingleCharacter) {
    // One letter, one occurrence: the whole string is the only substring.
    EXPECT_EQ(maxNumOfSubstrings("a"), (std::vector<std::string>{"a"}));
}

TEST(MaxNumOfSubstrings, AllSameLetter) {
    // Every 'a' must travel with the others, so the four collapse into one.
    EXPECT_EQ(maxNumOfSubstrings("aaaa"), (std::vector<std::string>{"aaaa"}));
}

TEST(MaxNumOfSubstrings, AllDistinctLetters) {
    // No letter repeats, so each character is its own substring.
    EXPECT_EQ(maxNumOfSubstrings("abcdef"),
              (std::vector<std::string>{"a", "b", "c", "d", "e", "f"}));
}

TEST(MaxNumOfSubstrings, InterleavedLettersMerge) {
    // "abab": 'a' at 0,2 and 'b' at 1,3 interlock, so the only valid substring
    // is the entire string.
    EXPECT_EQ(maxNumOfSubstrings("abab"), (std::vector<std::string>{"abab"}));
}

TEST(MaxNumOfSubstrings, PrefersShorterWhenCountsTie) {
    // "abaccb": 'a' (0,2) and 'b' (1,5) interlock into the whole string, so
    // only one substring is possible either way. "cc" wins the tie on length.
    EXPECT_EQ(maxNumOfSubstrings("abaccb"), (std::vector<std::string>{"cc"}));
}
