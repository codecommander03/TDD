#pragma once
#include <vector>

// Pick at most 4 pairwise non-overlapping intervals maximizing total weight;
// returns their original indices, sorted, lexicographically smallest on ties.
std::vector<int> maximumWeight(std::vector<std::vector<int>>& intervals);
