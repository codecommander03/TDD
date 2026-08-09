#include "dp/stone_game_2.hpp"
#include <algorithm>
#include <functional>

int stoneGameII(std::vector<int>& piles) {
    int n = piles.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n + 1, -1));

    std::vector<int> suf(n, 0);
    suf[n - 1] = piles[n - 1];
    for (int i = n - 2; i >= 0; --i) suf[i] = suf[i + 1] + piles[i];

    std::function<int(int, int)> help = [&](int i, int m) -> int {
        if (i >= n) return 0;
        if (i + 2 * m >= n) return suf[i];
        if (dp[i][m] != -1) return dp[i][m];

        int res = 0;
        for (int x = 1; x <= 2 * m && i + x <= n; ++x) {
            res = std::max(res, suf[i] - help(i + x, std::max(m, x)));
        }
        return dp[i][m] = res;
    };

    return help(0, 1);
}