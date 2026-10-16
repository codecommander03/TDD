#pragma once

#include <vector>

// Returns the sum, over all subarrays of nums, of the square of the number of
// distinct values in that subarray, modulo 1e9 + 7.
// Time: O(n log n), Space: O(n)
int sumCountsII(const std::vector<int>& nums);
