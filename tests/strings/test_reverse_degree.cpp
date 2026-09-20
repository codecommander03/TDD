#include <gtest/gtest.h>
#include "strings/reverse_degree.hpp"

TEST(ReverseDegree, Example1) {
    // Example 1: "abc" -> 26*1 + 25*2 + 24*3 = 26 + 50 + 72 = 148.
    EXPECT_EQ(reverseDegree("abc"), 148);
}

TEST(ReverseDegree, Example2) {
    // Example 2: "zaza" -> 1*1 + 26*2 + 1*3 + 26*4 = 1 + 52 + 3 + 104 = 160.
    EXPECT_EQ(reverseDegree("zaza"), 160);
}

TEST(ReverseDegree, SingleCharacterEnds) {
    // 'a' is the largest reverse position (26), 'z' the smallest (1); both at
    // index 1 so the multiplier is 1.
    EXPECT_EQ(reverseDegree("a"), 26);
    EXPECT_EQ(reverseDegree("z"), 1);
}

TEST(ReverseDegree, AllSameCharacter) {
    // "aaaa" -> 26 * (1 + 2 + 3 + 4) = 26 * 10 = 260.
    EXPECT_EQ(reverseDegree("aaaa"), 260);
}
