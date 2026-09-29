#pragma once
#include <vector>

// Returns true if some path from the top-left to the bottom-right cell,
// moving only down or right, spells out a valid parentheses string.
bool hasValidPath(std::vector<std::vector<char>>& grid);
