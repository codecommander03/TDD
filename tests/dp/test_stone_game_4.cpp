#include <gtest/gtest.h>
#include "dp/stone_game_4.hpp"

TEST(StoneGameIV, OneStoneAliceWins) {
    EXPECT_TRUE(winnerSquareGame(1));
}

TEST(StoneGameIV, TwoStonesAliceLoses) {
    EXPECT_FALSE(winnerSquareGame(2));
}

TEST(StoneGameIV, FourStonesPerfectSquare) {
    EXPECT_TRUE(winnerSquareGame(4));
}

TEST(StoneGameIV, SevenStonesAliceLoses) {
    EXPECT_FALSE(winnerSquareGame(7));
}

TEST(StoneGameIV, EightStonesAliceWins) {
    EXPECT_TRUE(winnerSquareGame(8));
}