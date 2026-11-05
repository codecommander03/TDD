#pragma once
#include <vector>

// Returns how many a in arr1 have |a - b| > d for every b in arr2.
// Sorts arr2 in place and appends a sentinel to it.
int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d);
