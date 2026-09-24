#include "arrays/min_operations_to_reduce_x_to_zero.hpp"
#include <algorithm>
#include <numeric>

int minOperations(std::vector<int>& nums, int x) {
    // The removed elements are a prefix plus a suffix, so what stays is a
    // subarray. Keeping the longest subarray summing to tot - x removes the
    // fewest elements.
    int n = static_cast<int>(nums.size());
    int tot = std::accumulate(begin(nums), end(nums), 0);
    if (tot < x) return -1;
    if (tot == x) return n;

    int l = 0, curr = 0, res = 1e9;
    for (int r = 0; r < n; r++) {
        curr += nums[r];
        // Everything is positive, so once the elements outside the window sum
        // to less than x the window is too wide.
        while (l < r && tot - curr < x) curr -= nums[l++];
        if (tot - curr == x) res = std::min(res, n - (r - l + 1));
    }

    if (res == 1e9) return -1;
    return res;
}
