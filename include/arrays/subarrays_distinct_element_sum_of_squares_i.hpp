#pragma once

#include <vector>

// Returns the sum, over all subarrays of nums, of the square of the number of
// distinct values in that subarray.
// Time: O(n^3 log n), Space: O(n)
int sumCounts(const std::vector<int>& nums);
