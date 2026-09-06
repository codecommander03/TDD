#include "dp/distinct_subsequences.hpp"

#include <vector>

int numDistinct(const std::string& s, const std::string& t) {
    int ns = static_cast<int>(s.size()), nt = static_cast<int>(t.size());

    // dp[i][j] = number of subsequences of s[i..ns) that spell out t[j..nt).
    std::vector<std::vector<long long>> dp(ns + 1, std::vector<long long>(nt + 1, 0));

    // An empty suffix of t is matched exactly one way: take nothing.
    for (int i = 0; i <= ns; i++) dp[i][nt] = 1;

    for (int i = ns - 1; i >= 0; i--) {
        for (int j = nt - 1; j >= 0; j--) {
            // s[i] can always be skipped; when it matches t[j] it may also be
            // consumed, which advances both suffixes.
            if (s[i] == t[j]) {
                dp[i][j] = (dp[i + 1][j] + dp[i + 1][j + 1]) % 1000000007;
            } else {
                dp[i][j] = dp[i + 1][j];
            }
        }
    }

    return static_cast<int>(dp[0][0]);
}
