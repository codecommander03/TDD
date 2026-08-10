#include "dp/stone_game_4.hpp"
#include <vector>

bool winnerSquareGame(int n) {
    std::vector<bool> dp(n + 1);
    for (int i = 0; i <= n; ++i) {
        if (dp[i]) continue;
        for (int j = 1; j * j + i <= n; ++j) dp[i + j * j] = true;
    }
    return dp[n];
}