#include <gtest/gtest.h>
#include "strings/maximum_length_substring.hpp"

TEST(MaximumLengthSubstring, BasicExample) {
    EXPECT_EQ(maximumLengthSubstring("bcbbbcba"), 4);
}

TEST(MaximumLengthSubstring, AllUniqueCharacters) {
    EXPECT_EQ(maximumLengthSubstring("aaaa"), 2);
}

TEST(MaximumLengthSubstring, NoRepeats) {
    EXPECT_EQ(maximumLengthSubstring("abcdef"), 6);
}

TEST(MaximumLengthSubstring, SingleCharacter) {
    EXPECT_EQ(maximumLengthSubstring("z"), 1);
}