#include "arrays/max_subarray_length.hpp"
#include <map>
#include <algorithm>

int maxSubarrayLength(std::vector<int>& nums, int k) {
    int n = nums.size(), last = -1, res = 0;
    std::map<int, std::vector<int>> m;

    for (int i = 0; i < n; ++i) {
        m[nums[i]].push_back(i);
        int cnt = m[nums[i]].size();
        if (cnt > k) last = std::max(last, m[nums[i]][cnt - k - 1]);
        res = std::max(res, i - last);
    }
    return res;
}