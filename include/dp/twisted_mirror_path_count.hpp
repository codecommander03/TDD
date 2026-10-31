#pragma once
#include <vector>

// Returns the number of paths from the top-left to the bottom-right cell moving
// only right or down, where entering a mirror (1) deflects a rightward move down
// and a downward move right, modulo 1e9 + 7.
int uniquePaths(std::vector<std::vector<int>>& grid);
