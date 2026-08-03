#include <gtest/gtest.h>
#include "dp/stone_game_3.hpp"

TEST(StoneGameIII, BobWinsExample) {
    std::vector<int> stoneValue = {1, 2, 3, 7};
    EXPECT_EQ(stoneGameIII(stoneValue), "Bob");
}

TEST(StoneGameIII, AliceWinsExample) {
    std::vector<int> stoneValue = {1, 2, 3, -9};
    EXPECT_EQ(stoneGameIII(stoneValue), "Alice");
}

TEST(StoneGameIII, TieExample) {
    std::vector<int> stoneValue = {1, 2, 3, 6};
    EXPECT_EQ(stoneGameIII(stoneValue), "Tie");
}

TEST(StoneGameIII, SingleStone) {
    std::vector<int> stoneValue = {-5};
    EXPECT_EQ(stoneGameIII(stoneValue), "Bob");
}

TEST(StoneGameIII, AllNegative) {
    std::vector<int> stoneValue = {-1, -2, -3};
    EXPECT_EQ(stoneGameIII(stoneValue), "Alice");
}