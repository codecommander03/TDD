#pragma once

#include <string>
#include <vector>

// The robot starts on 'S' with a full battery and moves to the four adjacent
// cells, spending one unit of energy per move; 'X' is a wall, 'L' is litter,
// and stepping on 'R' refills the battery. Returns the fewest moves that pick
// up every piece of litter, or -1 when the battery cannot stretch that far.
// Time: O(m * n * energy * 2^L), Space: O(m * n * energy * 2^L)
int minMoves(const std::vector<std::string>& classroom, int energy);
