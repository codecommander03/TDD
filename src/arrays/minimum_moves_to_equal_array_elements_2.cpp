#include "arrays/minimum_moves_to_equal_array_elements_2.hpp"
#include <algorithm>
#include <cstdlib>

int minMoves2(std::vector<int>& nums) {
    // The median minimizes the sum of absolute distances
    int n = static_cast<int>(nums.size());
    std::sort(nums.begin(), nums.end());
    int res = 0;
    for (int i = 0; i < n; i++) res += std::abs(nums[i] - nums[n / 2]);
    return res;
}
