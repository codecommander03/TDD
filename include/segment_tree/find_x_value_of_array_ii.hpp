#pragma once
#include <vector>

// queries[i] = [index, value, start, x]: set nums[index] = value (the change
// persists), then count the prefixes of nums[start..n-1] whose product modulo k
// equals x. Returns one answer per query.
// Time: O((n + q * log n) * k), Space: O(n * k)
std::vector<int> resultArray(std::vector<int>& nums, int k, std::vector<std::vector<int>>& queries);
