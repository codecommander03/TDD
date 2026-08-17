#include <gtest/gtest.h>
#include "dp/stone_game_5.hpp"

TEST(StoneGameV, Example1) {
    // Example 1: [6,2,3,4,5,5] -> 18 (11 + 5 + 2 across three rounds).
    std::vector<int> stones = {6, 2, 3, 4, 5, 5};
    EXPECT_EQ(stoneGameV(stones), 18);
}

TEST(StoneGameV, Example2AllSevens) {
    // Example 2: seven 7s -> 28.
    std::vector<int> stones = {7, 7, 7, 7, 7, 7, 7};
    EXPECT_EQ(stoneGameV(stones), 28);
}

TEST(StoneGameV, Example3SingleStone) {
    // Example 3: a single stone cannot be split -> score 0.
    std::vector<int> stones = {4};
    EXPECT_EQ(stoneGameV(stones), 0);
}

TEST(StoneGameV, TwoStones) {
    // Split [1|2]: Bob discards the larger (2), Alice scores min 1;
    // one stone remains -> 0. Total 1.
    std::vector<int> stones = {1, 2};
    EXPECT_EQ(stoneGameV(stones), 1);
}
