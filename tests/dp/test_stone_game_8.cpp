#include <gtest/gtest.h>
#include "dp/stone_game_8.hpp"

TEST(StoneGameVIII, Example1) {
    // Example 1: [-1,2,-3,4,-5] -> Alice leads by 5 under optimal play.
    std::vector<int> stones = {-1, 2, -3, 4, -5};
    EXPECT_EQ(stoneGameVIII(stones), 5);
}

TEST(StoneGameVIII, Example2) {
    // Example 2: [7,-6,5,10,5,-2,-6] -> difference of 13.
    std::vector<int> stones = {7, -6, 5, 10, 5, -2, -6};
    EXPECT_EQ(stoneGameVIII(stones), 13);
}

TEST(StoneGameVIII, Example3) {
    // Example 3: [-10,-12] -> Alice must take both and eats the whole loss.
    std::vector<int> stones = {-10, -12};
    EXPECT_EQ(stoneGameVIII(stones), -22);
}

TEST(StoneGameVIII, TwoStonesOnlyOneMove) {
    // With two stones the first move is forced to consume both.
    std::vector<int> stones = {3, 4};
    EXPECT_EQ(stoneGameVIII(stones), 7);
}

TEST(StoneGameVIII, AllPositiveAliceTakesEverything) {
    // Every prefix sum grows, so Alice sweeps the row and Bob never moves.
    std::vector<int> stones = {1, 2, 3, 4};
    EXPECT_EQ(stoneGameVIII(stones), 10);
}

TEST(StoneGameVIII, AllNegativeAliceMinimisesLoss) {
    // Alice takes the first two (-3) and leaves Bob the merged row worth -6.
    std::vector<int> stones = {-1, -2, -3};
    EXPECT_EQ(stoneGameVIII(stones), 3);
}

TEST(StoneGameVIII, StoppingEarlyBeatsTakingAll) {
    // Taking all of [5,-100,5,5] scores -85; stopping before the tail is better.
    std::vector<int> stones = {5, -100, 5, 5};
    EXPECT_EQ(stoneGameVIII(stones), -5);
}

TEST(StoneGameVIII, InputIsNotModified) {
    // The prefix sums are built into scratch space, not over the caller's row.
    std::vector<int> stones = {-1, 2, -3, 4, -5};
    std::vector<int> copy = stones;
    stoneGameVIII(stones);
    EXPECT_EQ(stones, copy);
}
