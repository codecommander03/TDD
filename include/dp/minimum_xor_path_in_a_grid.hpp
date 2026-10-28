#pragma once
#include <vector>

// Returns the minimum XOR of all cell values along a path from the top-left to
// the bottom-right cell, moving only down or right.
int minCost(std::vector<std::vector<int>>& grid);
