#include "arrays/min_sum_square_diff.hpp"

#include <algorithm>
#include <cstdlib>

long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2,
                           int k1, int k2) {
    int n = static_cast<int>(nums1.size()), M = 0;
    // Either array's changes shrink |nums1[i] - nums2[i]| by one, so pool them.
    long long k = 1LL * k1 + k2;
    std::vector<int> diff(n);

    for (int i = 0; i < n; i++)
        M = std::max(M, diff[i] = std::abs(nums1[i] - nums2[i]));

    // bucket[d]: how many indices have difference d.
    std::vector<int> bucket(M + 1);
    for (int x : diff) bucket[x]++;

    // Always shave the largest differences first, one level at a time.
    for (int i = M; i > 0 && k > 0; i--) {
        int take = std::min((long long)bucket[i], k);
        bucket[i] -= take;
        bucket[i - 1] += take;
        k -= take;
    }

    long long ans = 0;
    for (int i = 1; i <= M; i++)
        ans += 1LL * bucket[i] * i * i;

    return ans;
}
