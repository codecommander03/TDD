#include <gtest/gtest.h>
#include "strings/valid_sequence.hpp"

TEST(ValidSequence, ExactMatchNoMismatchNeeded) {
    auto result = validSequence("vbcca", "abc");
    EXPECT_EQ(result, (std::vector<int>{0, 1, 2}));
}

TEST(ValidSequence, OneMismatchUsed) {
    auto result = validSequence("bacdc", "abc");
    EXPECT_EQ(result, (std::vector<int>{1, 2, 4}));
}

TEST(ValidSequence, ImpossibleReturnsEmpty) {
    auto result = validSequence("aaaaaa", "aaabc");
    EXPECT_TRUE(result.empty());
}

TEST(ValidSequence, TwoCharacterWord2) {
    auto result = validSequence("abc", "ab");
    EXPECT_EQ(result, (std::vector<int>{0,1}));
}

TEST(ValidSequence, SingleCharacterWord2) {
    auto result = validSequence("nmm", "m");
    EXPECT_EQ(result, (std::vector<int>{0}));
}