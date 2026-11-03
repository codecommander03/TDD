#include "arrays/minimum_moves_to_equal_array_elements_3.hpp"
#include <algorithm>

int minMoves(std::vector<int>& nums) {
    // Elements can only go up, so every element must rise to the maximum
    int res = 0, x = *std::max_element(nums.begin(), nums.end());
    for (int i : nums) res += x - i;
    return res;
}
