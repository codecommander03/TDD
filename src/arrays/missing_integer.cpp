#include "arrays/missing_integer.hpp"
#include <set>

int missingInteger(std::vector<int>& nums) {
    int n = nums.size();
    std::set<int> s(nums.begin(), nums.end());

    int sum = nums[0];
    for (int i = 1; i < n; ++i) {
        if (nums[i] == nums[i - 1] + 1) sum += nums[i];
        else break;
    }

    while (s.count(sum)) ++sum;
    return sum;
}