#pragma once
#include <vector>

// Returns the minimum number of moves to make all elements equal, where a move
// increments a single element by 1.
// Takes a non-const reference so it does not clash with 453's
// minMoves(const std::vector<int>&) at link time.
int minMoves(std::vector<int>& nums);
