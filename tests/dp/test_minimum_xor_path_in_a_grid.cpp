#include <gtest/gtest.h>
#include "dp/minimum_xor_path_in_a_grid.hpp"

// LeetCode Example 1: right-down 1^2^4 = 7, down-right 1^3^4 = 6 -> 6
TEST(MinimumXorPathInAGrid, Example1) {
    std::vector<std::vector<int>> grid = {{1, 2}, {3, 4}};
    EXPECT_EQ(minCost(grid), 6);
}

// LeetCode Example 2: right-down 6^7^8 = 9, down-right 6^5^8 = 11 -> 9
TEST(MinimumXorPathInAGrid, Example2) {
    std::vector<std::vector<int>> grid = {{6, 7}, {5, 8}};
    EXPECT_EQ(minCost(grid), 9);
}

// LeetCode Example 3: single row, only path 2^7^5 = 0 -> 0
TEST(MinimumXorPathInAGrid, Example3) {
    std::vector<std::vector<int>> grid = {{2, 7, 5}};
    EXPECT_EQ(minCost(grid), 0);
}

// Single cell: the path is just that cell -> 5
TEST(MinimumXorPathInAGrid, SingleCell) {
    std::vector<std::vector<int>> grid = {{5}};
    EXPECT_EQ(minCost(grid), 5);
}

// Single column: only path 3^5 = 6 -> 6
TEST(MinimumXorPathInAGrid, SingleColumn) {
    std::vector<std::vector<int>> grid = {{3}, {5}};
    EXPECT_EQ(minCost(grid), 6);
}

// All zeros -> 0
TEST(MinimumXorPathInAGrid, AllZeros) {
    std::vector<std::vector<int>> grid = {{0, 0, 0}, {0, 0, 0}};
    EXPECT_EQ(minCost(grid), 0);
}

// Three paths: RRD 1^2^3^6 = 6, RDR 1^2^5^6 = 0, DRR 1^4^5^6 = 6.
// The minimum runs through the middle, not along either edge -> 0
TEST(MinimumXorPathInAGrid, MinimumThroughMiddle) {
    std::vector<std::vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
    EXPECT_EQ(minCost(grid), 0);
}
