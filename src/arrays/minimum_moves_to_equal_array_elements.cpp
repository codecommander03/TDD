#include "arrays/minimum_moves_to_equal_array_elements.hpp"
#include <algorithm>

int minMoves(const std::vector<int>& nums) {
    // Incrementing n - 1 elements is the same as decrementing one, so every
    // element must come down to the minimum
    int res = 0, x = *std::min_element(nums.begin(), nums.end());
    for (int i : nums) res += i - x;
    return res;
}
