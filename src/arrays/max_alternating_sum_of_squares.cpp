#include "arrays/max_alternating_sum_of_squares.hpp"
#include <algorithm>
#include <cstdlib>

long long maxAlternatingSum(std::vector<int>& nums) {
    // Smallest squares go to the floor(n/2) subtracted (odd) slots, the rest are added.
    std::sort(nums.begin(), nums.end(), [](int a, int b) {
        return std::abs(a) < std::abs(b);
    });
    int n = static_cast<int>(nums.size());
    long long res = 0;
    for (int i = 0; i < n; i++) res += (i < n / 2 ? -1 : 1) * 1LL * nums[i] * nums[i];
    return res;
}
