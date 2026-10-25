#include <gtest/gtest.h>
#include "graphs/number_of_closed_islands.hpp"

// LeetCode Example 1: two land groups fully ringed by water; the right-edge
// zeros touch the border and don't count -> 2
TEST(NumberOfClosedIslands, Example1) {
    std::vector<std::vector<int>> grid = {
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0}};
    EXPECT_EQ(closedIsland(grid), 2);
}

// LeetCode Example 2: only the centre cell (1,2) is enclosed -> 1
TEST(NumberOfClosedIslands, Example2) {
    std::vector<std::vector<int>> grid = {
        {0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0}};
    EXPECT_EQ(closedIsland(grid), 1);
}

// LeetCode Example 3: outer ring of land plus the centre cell -> 2
TEST(NumberOfClosedIslands, Example3) {
    std::vector<std::vector<int>> grid = {
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1}};
    EXPECT_EQ(closedIsland(grid), 2);
}

// Single land cell sits on the border -> 0
TEST(NumberOfClosedIslands, SingleLandCell) {
    std::vector<std::vector<int>> grid = {{0}};
    EXPECT_EQ(closedIsland(grid), 0);
}

// All water -> 0
TEST(NumberOfClosedIslands, AllWater) {
    std::vector<std::vector<int>> grid = {{1, 1}, {1, 1}};
    EXPECT_EQ(closedIsland(grid), 0);
}

// All land: one island that touches the border -> 0
TEST(NumberOfClosedIslands, AllLand) {
    std::vector<std::vector<int>> grid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    EXPECT_EQ(closedIsland(grid), 0);
}

// One land cell in the middle ringed by water -> 1
TEST(NumberOfClosedIslands, SingleEnclosedCell) {
    std::vector<std::vector<int>> grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    EXPECT_EQ(closedIsland(grid), 1);
}
