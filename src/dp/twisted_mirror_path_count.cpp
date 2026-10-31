#include "dp/twisted_mirror_path_count.hpp"

#include <vector>

int uniquePaths(std::vector<std::vector<int>>& grid) {
    int m = static_cast<int>(grid.size()), n = static_cast<int>(grid[0].size());
    int MOD = 1e9 + 7;

    // DP arrays tracking paths LEAVING cell (i, j) in a specific direction
    std::vector<std::vector<int>> outR(m, std::vector<int>(n, 0));
    std::vector<std::vector<int>> outD(m, std::vector<int>(n, 0));

    // Start cell sends out 1 path that can branch Right and Down
    outR[0][0] = 1;
    outD[0][0] = 1;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) continue;

            // Paths ENTERING (i, j) from the left and top
            int inR = (j > 0) ? outR[i][j - 1] : 0;
            int inD = (i > 0) ? outD[i - 1][j] : 0;

            if (grid[i][j] == 0) { // Empty Cell
                // Can choose to move Right or Down
                outR[i][j] = (inR + inD) % MOD;
                outD[i][j] = (inR + inD) % MOD;
            } else { // Mirror Cell (grid[i][j] == 1)
                // Deflected: Right-moving goes Down, Down-moving goes Right
                outR[i][j] = inD;
                outD[i][j] = inR;
            }
        }
    }

    // The answer is all valid paths ARRIVING at the bottom-right cell
    int targetInR = outR[m - 1][n - 2];
    int targetInD = outD[m - 2][n - 1];

    return (targetInR + targetInD) % MOD;
}
