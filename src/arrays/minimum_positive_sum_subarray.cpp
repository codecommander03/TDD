#include "arrays/minimum_positive_sum_subarray.hpp"
#include <algorithm>

int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
    int n = static_cast<int>(nums.size()), res = 1e9;
    for (int len = l; len <= r; len++) {
        int sum = 0;
        for (int j = 0; j < len; j++) sum += nums[j];
        if (sum > 0) res = std::min(res, sum);
        for (int j = len; j < n; j++) {
            sum += nums[j] - nums[j - len];
            if (sum > 0) res = std::min(res, sum);
        }
    }
    if (res == 1e9) return -1;
    return res;
}
