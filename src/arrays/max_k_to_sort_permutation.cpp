#include "arrays/max_k_to_sort_permutation.hpp"
#include <algorithm>

int sortPermutation(const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    std::vector<int> v = nums;
    std::sort(v.begin(), v.end());
    int res = (1 << 30) - 1;
    for (int i = 0; i < n; i++) {
        if (nums[i] == v[i]) continue;
        res &= nums[i];
    }
    if (res == (1 << 30) - 1) return 0;
    return res;
}
