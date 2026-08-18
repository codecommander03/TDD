#include "arrays/largest_almost_missing_integer.hpp"
#include <algorithm>
#include <map>
#include <set>

int largestInteger(std::vector<int>& nums, int k) {
    std::map<int, int> windowsContaining;
    int n = static_cast<int>(nums.size());

    // For each size-k window, count each distinct value once.
    for (int i = 0; i <= n - k; ++i) {
        std::set<int> distinct;
        for (int j = i; j < i + k; ++j) distinct.insert(nums[j]);
        for (int num : distinct) windowsContaining[num]++;
    }

    // "Almost missing" = appears in exactly one window; take the largest.
    int res = -1;
    for (const auto& entry : windowsContaining) {
        if (entry.second == 1) res = std::max(res, entry.first);
    }
    return res;
}
