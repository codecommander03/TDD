#include "arrays/min_sum_of_lengths.hpp"
#include <map>
#include <algorithm>

int minSumOfLengths(std::vector<int>& arr, int target) {
    const int INF = 1e9;
    int n = static_cast<int>(arr.size());
    std::vector<int> l(n, INF), r(n, INF);

    // l[i]: shortest subarray summing to target that ends at index i or earlier.
    // m maps a prefix sum to the last index where it occurred; values are
    // positive, so prefix sums strictly increase and the last index is the
    // closest one, i.e. the shortest match.
    std::map<int, int> m;
    int sum = arr[0];
    m[0] = -1;
    m[sum] = 0;
    if (sum == target) l[0] = 1;
    for (int i = 1; i < n; ++i) {
        sum += arr[i];
        m[sum] = i;
        l[i] = l[i - 1];
        if (m.count(sum - target)) l[i] = std::min(l[i], i - m[sum - target]);
    }

    // r[i]: shortest subarray summing to target that starts at index i or later.
    // Same idea on suffix sums, scanning right to left.
    m.clear();
    sum = arr[n - 1];
    m[0] = n;
    m[sum] = n - 1;
    if (sum == target) r[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        sum += arr[i];
        m[sum] = i;
        r[i] = r[i + 1];
        if (m.count(sum - target)) r[i] = std::min(r[i], m[sum - target] - i);
    }

    // Split at i: best subarray fully left of i plus best one starting at i.
    int res = INF;
    for (int i = 1; i < n; ++i) {
        if (l[i - 1] < INF && r[i] < INF) res = std::min(res, l[i - 1] + r[i]);
    }
    return res == INF ? -1 : res;
}
