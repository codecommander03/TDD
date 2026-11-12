#include "arrays/longest_strictly_increasing_or_decreasing_subarray.hpp"
#include <algorithm>

int longestMonotonicSubarray(const std::vector<int>& nums) {
    // Lengths of the strictly decreasing / increasing runs ending at i
    int n = static_cast<int>(nums.size()), res = 1, dec = 1, inc = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i - 1] > nums[i]) dec++;
        else dec = 1;
        if (nums[i - 1] < nums[i]) inc++;
        else inc = 1;
        res = std::max({res, dec, inc});
    }
    return res;
}
