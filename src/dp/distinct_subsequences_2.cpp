#include "dp/distinct_subsequences_2.hpp"

#include <vector>

int distinctSubseqII(const std::string& s) {
    const int mod = 1000000007;

    int res = 0;
    // dp[i] = number of distinct non-empty subsequences ending with 'a' + i.
    std::vector<int> dp(26, 0);

    for (char c : s) {
        int i = c - 'a';
        // Appending c to every subsequence so far (plus the single "c") gives
        // res + 1 candidates; the dp[i] that already ended in c are duplicates.
        long long more = (res + 1 - dp[i] + mod) % mod;
        res = static_cast<int>((res + more) % mod);
        dp[i] = static_cast<int>((dp[i] + more) % mod);
    }

    return res;
}
