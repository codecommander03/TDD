#pragma once
#include <vector>

// Index i has instability score max(nums[0..i]) - min(nums[i..n-1]), and is
// stable when that score is <= k. Return the smallest stable index, or -1.
// Time: O(n), Space: O(n)
int firstStableIndex(std::vector<int>& nums, int k);
