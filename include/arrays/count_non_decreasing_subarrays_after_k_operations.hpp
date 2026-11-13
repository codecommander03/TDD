#pragma once
#include <vector>

// Returns how many subarrays can be made non-decreasing with at most k
// operations, where an operation increments one element by 1 (each subarray is
// considered on its own).
long long countNonDecreasingSubarrays(std::vector<int>& nums, int k);
