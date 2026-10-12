#pragma once

#include <vector>

// Returns the maximum sum of squares of k elements chosen after any number of
// (nums[i], nums[j]) -> (nums[i] AND nums[j], nums[i] OR nums[j]) operations,
// modulo 1e9 + 7.
int maxSum(std::vector<int>& nums, int k);
