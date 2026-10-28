#include "dp/minimum_xor_path_in_a_grid.hpp"

#include <algorithm>
#include <unordered_set>
#include <vector>

int minCost(std::vector<std::vector<int>>& grid) {
    int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size());

    // dp[i][j] holds every XOR sum reachable at cell (i, j)
    std::vector<std::vector<std::unordered_set<int>>> dp(n, std::vector<std::unordered_set<int>>(m));

    dp[0][0].insert(grid[0][0]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Pull all reachable XOR sums from the top cell
            if (i > 0) {
                for (int val : dp[i - 1][j]) dp[i][j].insert(val ^ grid[i][j]);
            }
            // Pull all reachable XOR sums from the left cell
            if (j > 0) {
                for (int val : dp[i][j - 1]) dp[i][j].insert(val ^ grid[i][j]);
            }
        }
    }

    int min_xor = 1e9;
    for (int val : dp[n - 1][m - 1]) min_xor = std::min(min_xor, val);

    return min_xor;
}
