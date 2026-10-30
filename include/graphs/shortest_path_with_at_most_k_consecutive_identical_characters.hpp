#pragma once
#include <string>
#include <vector>

// Directed weighted graph; each node carries a lowercase label. Returns the
// minimum total weight of a path from 0 to n - 1 whose label sequence has no
// run of identical characters longer than k, or -1 if none exists.
// Time: O((n * k + e * k) log(n * k)), Space: O(n * k + e)
int shortestPath(int n, std::vector<std::vector<int>>& edges, std::string labels, int k);
