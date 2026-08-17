#include "dp/stone_game_5.hpp"
#include <algorithm>
#include <functional>

int stoneGameV(std::vector<int>& stones) {
    int n = static_cast<int>(stones.size());
    if (n < 2) return 0;

    // Prefix sums so any sub-row's total is O(1).
    std::vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; ++i) pre[i + 1] = pre[i] + stones[i];

    // memo[l][r] = best score Alice can get from the row stones[l..r].
    std::vector<std::vector<int>> memo(n, std::vector<int>(n, -1));

    std::function<int(int, int)> solve = [&](int l, int r) -> int {
        if (l == r) return 0;
        if (memo[l][r] != -1) return memo[l][r];

        int ans = 0;
        for (int i = l; i < r; ++i) {
            int leftSum = pre[i + 1] - pre[l];
            int rightSum = pre[r + 1] - pre[i + 1];

            if (leftSum < rightSum) {
                ans = std::max(ans, leftSum + solve(l, i));
            } else if (leftSum > rightSum) {
                ans = std::max(ans, rightSum + solve(i + 1, r));
            } else {
                ans = std::max(ans, leftSum + std::max(solve(l, i), solve(i + 1, r)));
            }
        }
        return memo[l][r] = ans;
    };

    return solve(0, n - 1);
}
