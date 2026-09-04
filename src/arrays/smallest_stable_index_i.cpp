#include "arrays/smallest_stable_index_i.hpp"
#include <algorithm>

int firstStableIndex(std::vector<int>& nums, int k) {
    int n = static_cast<int>(nums.size());
    if (n == 0) return -1;

    // mx[i] = max of the prefix nums[0..i], mn[i] = min of the suffix
    // nums[i..n-1]; together they give index i's instability score in O(1).
    std::vector<int> mn(n), mx(n);

    mx[0] = nums[0];
    for (int i = 1; i < n; ++i) mx[i] = std::max(mx[i - 1], nums[i]);

    mn[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) mn[i] = std::min(mn[i + 1], nums[i]);

    for (int i = 0; i < n; ++i) {
        if (mx[i] - mn[i] <= k) return i;
    }

    return -1;
}
