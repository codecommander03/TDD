#include "arrays/find_target_indices.hpp"
#include <algorithm>

std::vector<int> targetIndices(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int n = static_cast<int>(nums.size());
    std::vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == target) res.push_back(i);
    }
    return res;
}
