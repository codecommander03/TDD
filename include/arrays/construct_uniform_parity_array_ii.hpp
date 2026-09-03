#pragma once
#include <vector>

// Same construction as Construct Uniform Parity Array I, except that
// nums2[i] = nums1[i] - nums1[j] is only allowed when the difference is >= 1,
// i.e. only a strictly smaller element may be subtracted. Named uniformArrayII
// because problem I already claims uniformArray in the global namespace.
// Time: O(n log n), Space: O(1)
bool uniformArrayII(std::vector<int>& nums1);
