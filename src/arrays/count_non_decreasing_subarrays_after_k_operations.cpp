#include "arrays/count_non_decreasing_subarrays_after_k_operations.hpp"

long long countNonDecreasingSubarrays(std::vector<int>& nums, int k) {
    // water: ops to raise nums[l..r] to its running max; sweep l right to left
    int n = static_cast<int>(nums.size()), head = n, tail = n, r = n - 1;
    std::vector<int> starts(n);  // where each plateau starts, left to right: starts[head..tail)
    long long ans = 0, water = 0;
    for (int l = n - 1; l >= 0; --l) {
        int x = nums[l];
        while (head < tail && nums[starts[head]] <= x) {  // x floods the plateau that starts at starts[head]
            int s = starts[head++];
            int end = head < tail ? starts[head] : r + 1;
            water += 1LL * (x - nums[s]) * (end - s);
        }
        starts[--head] = l;
        while (water > k) {  // the right end leaves with its water
            water -= nums[starts[tail - 1]] - nums[r];
            if (starts[tail - 1] == r)
                --tail;
            --r;
        }
        ans += r - l + 1;
    }
    return ans;
}
