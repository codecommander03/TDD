#pragma once

#include <vector>

// Returns the minimum sum of (nums1[i] - nums2[i])^2 after at most k1 +/-1
// changes to nums1 and at most k2 +/-1 changes to nums2.
long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2,
                           int k1, int k2);
