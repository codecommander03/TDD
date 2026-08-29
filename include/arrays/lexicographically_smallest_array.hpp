#pragma once

#include <vector>

// Two elements may be swapped whenever their values differ by at most limit,
// and swaps may be repeated; returns the smallest array those swaps can reach.
std::vector<int> lexicographicallySmallestArray(const std::vector<int>& nums, int limit);
