#include "dp/number_of_sets_of_line_segments.hpp"

#include <vector>

int numberOfSets(int n, int k) {
    const int mod = 1e9 + 7;

    // dp[i][j] = ways to draw j segments using only the points 0..i.
    std::vector<std::vector<int>> dp(n, std::vector<int>(k + 1, 0));

    for (int i = 0; i < n; ++i) dp[i][0] = 1;

    for (int j = 1; j <= k; ++j) {
        // running_sum = sum of dp[t][j-1] for t < i, i.e. every way to finish
        // the j-th segment at point i by starting it at some earlier point.
        int running_sum = 0;
        for (int i = 1; i < n; ++i) {
            running_sum = (running_sum + dp[i - 1][j - 1]) % mod;
            // Either point i is unused, or it is the right end of segment j.
            dp[i][j] = (dp[i - 1][j] + running_sum) % mod;
        }
    }

    return dp[n - 1][k];
}
