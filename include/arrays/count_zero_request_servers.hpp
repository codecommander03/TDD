#pragma once
#include <vector>

// For each query q, returns how many of the n servers received no request in
// the inclusive time interval [q - x, q]. Sorts logs in place by time.
std::vector<int> countServers(int n, std::vector<std::vector<int>>& logs, int x,
                              std::vector<int>& queries);
