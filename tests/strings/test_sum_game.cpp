#include <gtest/gtest.h>
#include "strings/sum_game.hpp"

TEST(SumGame, NoBlanksUnequalHalves) {
    // "25" vs "23": sums differ already, so Alice wins without moving.
    EXPECT_TRUE(sumGame("2523"));
}

TEST(SumGame, NoBlanksEqualHalves) {
    // "50" vs "23": 5 == 5, nothing left to play, Bob wins.
    EXPECT_FALSE(sumGame("5023"));
}

TEST(SumGame, OddNumberOfBlanks) {
    // Three blanks: Alice moves last and can always break the balance.
    EXPECT_TRUE(sumGame("??5?"));
    // A single blank leaves Alice free to pick any digit but 5.
    EXPECT_TRUE(sumGame("5?"));
}

TEST(SumGame, EvenBlanksBobBalances) {
    // "?329" vs "5???": 14 + 4.5 == 5 + 13.5, so Bob can always answer.
    EXPECT_FALSE(sumGame("?3295???"));
}

TEST(SumGame, EvenBlanksAliceBreaksBalance) {
    // "25" vs "??": 7 != 9, so the blanks cannot reach the known side.
    EXPECT_TRUE(sumGame("25??"));
}

TEST(SumGame, BlanksSplitEvenlyAcrossHalves) {
    // One blank per half: Bob mirrors Alice's digit, so equal known sums hold.
    EXPECT_FALSE(sumGame("1?1?"));
    // The mirrored pair cannot repair a known gap of one.
    EXPECT_TRUE(sumGame("1?2?"));
    // Unequal known sums cannot be repaired by the mirrored pair.
    EXPECT_TRUE(sumGame("1?3?"));
}

TEST(SumGame, AllBlanks) {
    // Every digit is free and the halves are symmetric, so Bob mirrors.
    EXPECT_FALSE(sumGame("????"));
}

TEST(SumGame, TwoBlanksInOneHalfExactlyOffset) {
    // "??" vs "45": the two blanks are worth 4.5 each, exactly the known 9.
    EXPECT_FALSE(sumGame("??45"));
    // One more on the known side and the balance is gone.
    EXPECT_TRUE(sumGame("??46"));
    // Nine per blank is what Alice would need, and Bob never allows it.
    EXPECT_TRUE(sumGame("??99"));
}
