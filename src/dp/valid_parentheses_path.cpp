#include "dp/valid_parentheses_path.hpp"

#include <bitset>
#include <vector>

bool hasValidPath(std::vector<std::vector<char>>& grid) {
    int m = static_cast<int>(grid.size()), n = static_cast<int>(grid[0].size());

    // A valid string has even length and must open with '('. ')' is 41, so
    // the low bit of a cell is set exactly when it holds ')'.
    if ((m + n - 1) & 1 || (grid[0][0] & 1)) return false;

    // dp[i][j] bit k = some path reaching cell (i, j) has open balance k
    // before (i, j) is read. 102 bits is enough: a balance above ~100 can
    // never fall back to 0 in the steps left, so losing it is harmless.
    std::vector<std::vector<std::bitset<102>>> dp(m + 1, std::vector<std::bitset<102>>(n + 1));
    dp[0][0].set(0);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // '(' shifts every balance up by 1; ')' shifts up 1 then down 2,
            // a net -1 that also drops balance 0, since it would go negative.
            auto b = (dp[i][j] << 1) >> ((grid[i][j] & 1) << 1);

            dp[i + 1][j] |= b;
            dp[i][j + 1] |= b;
        }
    }

    // dp[m][n - 1] is fed only by the last cell, so it holds the balances
    // after the full path has been read.
    return dp[m][n - 1].test(0);
}
