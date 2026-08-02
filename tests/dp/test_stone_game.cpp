#include <gtest/gtest.h>
#include "dp/stone_game.hpp"

TEST(StoneGame, ExampleAliceWins) {
    std::vector<int> piles = {5, 3, 4, 5};
    EXPECT_TRUE(stoneGame(piles));
}

TEST(StoneGame, AllEqualPiles) {
    std::vector<int> piles = {3, 7, 2, 3};
    EXPECT_FALSE(stoneGame(piles)); 
}

TEST(StoneGame, LargerEvenPileCount) {
    std::vector<int> piles = {7, 8, 8, 10};
    EXPECT_TRUE(stoneGame(piles));
}
