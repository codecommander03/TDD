#pragma once

#include <vector>

// Returns the minimum number of swaps needed to sort nums (distinct positive
// integers) by digit sum ascending, breaking ties by the smaller value first.
// Time: O(n log n), Space: O(n)
int minSwaps(std::vector<int>& nums);
