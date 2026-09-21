#pragma once
#include <vector>

// Removing a (possibly empty) prefix and suffix leaves a non-empty subarray, so
// result[x] is the number of non-empty subarrays of nums whose product modulo k
// equals x. Returns a vector of size k.
// Time: O(n * k), Space: O(k)
std::vector<long long> resultArray(std::vector<int>& nums, int k);
