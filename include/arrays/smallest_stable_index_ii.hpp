#pragma once
#include <vector>

// Index i has instability score max(nums[0..i]) - min(nums[i..n-1]), and is
// stable when that score is <= k. Return the smallest stable index, or -1.
// Same statement as Smallest Stable Index I with n up to 1e5 and values up
// to 1e9, so the linear prefix/suffix scan is what is required.
// Time: O(n), Space: O(n)
int firstStableIndexII(std::vector<int>& nums, int k);
