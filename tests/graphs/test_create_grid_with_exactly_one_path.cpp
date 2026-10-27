#include <gtest/gtest.h>
#include "graphs/create_grid_with_exactly_one_path.hpp"

// Any valid grid is accepted, so instead of comparing strings these tests check
// the grid's properties: it is m x n, uses only '.' and '#', and has exactly
// one right/down path from (0,0) to (m-1,n-1).

// Counts right/down paths through '.' cells. Returns 0 if a corner is blocked.
static long long countPaths(const std::vector<std::string>& grid) {
    int m = static_cast<int>(grid.size()), n = static_cast<int>(grid[0].size());
    std::vector<std::vector<long long>> dp(m, std::vector<long long>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != '.') continue;
            if (i == 0 && j == 0) dp[i][j] = 1;
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

static void expectValid(int m, int n) {
    std::vector<std::string> grid = createGrid(m, n);
    ASSERT_EQ(static_cast<int>(grid.size()), m);
    for (const std::string& row : grid) {
        ASSERT_EQ(static_cast<int>(row.size()), n);
        for (char c : row) EXPECT_TRUE(c == '.' || c == '#');
    }
    EXPECT_EQ(countPaths(grid), 1) << "m=" << m << " n=" << n;
}

// Sanity check of the helper on the example output ["..#","#.."]:
// (0,0)->(0,1)->(1,1)->(1,2) is the only route -> 1.
// An open 2x3 grid has C(3,1) = 3 routes.
TEST(CreateGridWithExactlyOnePath, HelperCountsPaths) {
    EXPECT_EQ(countPaths({"..#", "#.."}), 1);
    EXPECT_EQ(countPaths({"...", "..."}), 3);
    EXPECT_EQ(countPaths({".#", "#."}), 0);
}

// LeetCode example: m = 2, n = 3
TEST(CreateGridWithExactlyOnePath, Example) {
    expectValid(2, 3);
}

// 1x1: the single cell is both start and end -> one path
TEST(CreateGridWithExactlyOnePath, SingleCell) {
    expectValid(1, 1);
}

// A single row or column can only ever have one path
TEST(CreateGridWithExactlyOnePath, SingleRowOrColumn) {
    expectValid(1, 5);
    expectValid(5, 1);
}

// Square grid, where an open grid would have C(4,2) = 6 paths
TEST(CreateGridWithExactlyOnePath, Square) {
    expectValid(3, 3);
}

// Every size allowed by the constraints (1 <= m, n <= 25)
TEST(CreateGridWithExactlyOnePath, AllSizes) {
    for (int m = 1; m <= 25; m++) {
        for (int n = 1; n <= 25; n++) expectValid(m, n);
    }
}
