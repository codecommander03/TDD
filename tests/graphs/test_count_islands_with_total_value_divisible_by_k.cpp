#include <gtest/gtest.h>
#include "graphs/count_islands_with_total_value_divisible_by_k.hpp"

// LeetCode Example 1: four islands with sums 2+1+5=8, 5, 1+1+4+7+2=15, 8;
// only 5 and 15 are divisible by 5 -> 2
TEST(CountIslandsWithTotalValueDivisibleByK, Example1) {
    std::vector<std::vector<int>> grid = {
        {0, 2, 1, 0, 0},
        {0, 5, 0, 0, 5},
        {0, 0, 1, 0, 0},
        {0, 1, 4, 7, 0},
        {0, 2, 0, 0, 8}};
    EXPECT_EQ(countIslands(grid, 5), 2);
}

// LeetCode Example 2: checkerboard of six isolated 3s, each divisible by 3 -> 6
TEST(CountIslandsWithTotalValueDivisibleByK, Example2) {
    std::vector<std::vector<int>> grid = {
        {3, 0, 3, 0},
        {0, 3, 0, 3},
        {3, 0, 3, 0}};
    EXPECT_EQ(countIslands(grid, 3), 6);
}

// All water: no islands -> 0
TEST(CountIslandsWithTotalValueDivisibleByK, AllWater) {
    std::vector<std::vector<int>> grid = {{0, 0}, {0, 0}};
    EXPECT_EQ(countIslands(grid, 2), 0);
}

// Single cell 4, k = 2: 4 % 2 == 0 -> 1
TEST(CountIslandsWithTotalValueDivisibleByK, SingleCellDivisible) {
    std::vector<std::vector<int>> grid = {{4}};
    EXPECT_EQ(countIslands(grid, 2), 1);
}

// Single cell 5, k = 3: 5 % 3 != 0 -> 0
TEST(CountIslandsWithTotalValueDivisibleByK, SingleCellNotDivisible) {
    std::vector<std::vector<int>> grid = {{5}};
    EXPECT_EQ(countIslands(grid, 3), 0);
}

// All land is one island: 1+2+3+4 = 10; divisible by 5 but not by 3
TEST(CountIslandsWithTotalValueDivisibleByK, AllLandOneIsland) {
    std::vector<std::vector<int>> grid = {{1, 2}, {3, 4}};
    EXPECT_EQ(countIslands(grid, 5), 1);
    std::vector<std::vector<int>> grid2 = {{1, 2}, {3, 4}};
    EXPECT_EQ(countIslands(grid2, 3), 0);
}

// Diagonal cells aren't connected: two islands of 2 each, k = 4 -> 0
// (a diagonal-connected bug would see one island of 4 and return 1)
TEST(CountIslandsWithTotalValueDivisibleByK, DiagonalNotConnected) {
    std::vector<std::vector<int>> grid = {{2, 0}, {0, 2}};
    EXPECT_EQ(countIslands(grid, 4), 0);
}
