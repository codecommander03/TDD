#pragma once
#include <vector>

// Each operation removes the leftmost or rightmost element and subtracts it
// from x; returns the fewest operations that bring x to exactly 0, or -1.
int minOperations(std::vector<int>& nums, int x);
