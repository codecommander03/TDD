#pragma once

#include <vector>

// Returns the maximum score of sum(nums[i]^2 at even i) - sum(nums[i]^2 at odd i)
// over all rearrangements of nums.
// Time: O(n log n), Space: O(log n)
long long maxAlternatingSum(std::vector<int>& nums);
