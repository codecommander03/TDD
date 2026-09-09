#include "math/count_commas_in_range_ii.hpp"

#include <climits>

// Counting per number is impossible at n = 1e18, so count per comma position
// instead: the k-th comma (k = 1, 2, ...) appears in exactly the integers
// x >= 1000^k, of which there are n - 1000^k + 1 in [1, n]. Summing that over
// every power of 1000 up to n gives the total.
long long countCommas(long long n) {
    long long res = 0, step = 1000;

    while (n >= step) {
        res += (n - step + 1);
        // The next power of 1000 would overflow, and n cannot reach it anyway.
        if (step > LLONG_MAX / 1000) break;
        step *= 1000;
    }

    return res;
}
