#include "math/kth_smallest_amount.hpp"

#include <algorithm>
#include <numeric>

// Every coin i can only produce its own multiples, so the reachable amounts are
// the union of the arithmetic progressions {coins[i], 2*coins[i], ...}. The count
// of reachable amounts <= x is monotone in x, so we binary search for the
// smallest x whose count reaches k, and evaluate that count with
// inclusion-exclusion over subsets: a subset's shared multiples are the
// multiples of its LCM.
long long findKthSmallest(std::vector<int>& coins, int k) {
    const int n = static_cast<int>(coins.size());
    const int m = 1 << n;

    std::sort(coins.begin(), coins.end());

    // The answer never exceeds the smallest coin times k, which caps how large
    // an LCM can be before it stops contributing to any count.
    long long lo = k, hi = static_cast<long long>(coins[0]) * k + 1;

    std::vector<int> bits(m, 0);
    std::vector<long long> lcm(m, 0);
    for (int mask = 1; mask < m; ++mask) {
        long long cur = 1;
        for (int i = 0; i < n; ++i) {
            if (!((mask >> i) & 1)) continue;
            ++bits[mask];
            long long reduced = cur / std::gcd(cur, static_cast<long long>(coins[i]));
            if (reduced > hi / coins[i]) {
                // The LCM overflows past the search range; park it above hi so
                // it is skipped for every candidate instead of wrapping around.
                cur = hi + 1;
                break;
            }
            cur = reduced * coins[i];
        }
        lcm[mask] = cur;
    }

    // How many amounts in [1, x] are a multiple of at least one coin.
    auto reachable = [&](long long x) {
        long long count = 0;
        for (int mask = 1; mask < m; ++mask) {
            if (lcm[mask] > x) continue;
            if (bits[mask] & 1) count += x / lcm[mask];
            else count -= x / lcm[mask];
        }
        return count;
    };

    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (reachable(mid) >= k) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}
