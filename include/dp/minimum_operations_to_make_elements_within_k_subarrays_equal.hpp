#pragma once
#include <vector>

// Returns the minimum number of +1/-1 operations so that nums contains at least
// k non-overlapping subarrays of size exactly x, each with all elements equal.
long long minOperations(std::vector<int>& nums, int x, int k);
