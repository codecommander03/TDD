#pragma once
#include <vector>

// Given n distinct integers, decide whether nums2 (where each nums2[i] is
// either nums1[i] or nums1[i] - nums1[j] for some j != i) can be made all
// odd or all even. It always can, so the answer is unconditionally true.
// Time: O(1), Space: O(1)
bool uniformArray(std::vector<int>& nums1);
