#include "arrays/min_operations_to_sort_permutation.hpp"
#include <algorithm>

int minOperations(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    int asc = 1, dsc = 1;

    for (int i = 1; i < n; i++) {
        asc += nums[i] == (nums[i - 1] + 1) % n;
        dsc += nums[i - 1] == (nums[i] + 1) % n;
    }

    if (asc == n && !nums.front())
        return 0;

    if (asc == n)
        return std::min(n - nums.front(), nums.front() + 2);

    if (dsc == n)
        return std::min(n - nums.back(), nums.back()) + 1;

    return -1;
}
