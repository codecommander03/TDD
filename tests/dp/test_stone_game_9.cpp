#include <gtest/gtest.h>
#include "dp/stone_game_9.hpp"

TEST(StoneGameIX, Example1AliceWins) {
    // Example 1: [2,1] -> Alice wins; Bob is forced to make the sum 3.
    std::vector<int> stones = {2, 1};
    EXPECT_TRUE(stoneGameIX(stones));
}

TEST(StoneGameIX, Example2AliceLoses) {
    // Example 2: [2] -> a single stone leaves Alice unable to win.
    std::vector<int> stones = {2};
    EXPECT_FALSE(stoneGameIX(stones));
}

TEST(StoneGameIX, Example3AliceLoses) {
    // Example 3: [5,1,2,4,3] -> Alice loses under optimal play.
    std::vector<int> stones = {5, 1, 2, 4, 3};
    EXPECT_FALSE(stoneGameIX(stones));
}

TEST(StoneGameIX, SingleMultipleOfThree) {
    // One stone divisible by 3: Alice's only move makes the sum divisible -> loses.
    std::vector<int> stones = {3};
    EXPECT_FALSE(stoneGameIX(stones));
}

TEST(StoneGameIX, ForcesOpponentToThree) {
    // [1,2]: Alice removes 2, Bob is forced to remove 1 (sum 3) -> Alice wins.
    std::vector<int> stones = {1, 2};
    EXPECT_TRUE(stoneGameIX(stones));
}
