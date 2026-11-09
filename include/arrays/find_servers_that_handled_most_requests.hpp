#pragma once
#include <vector>

// Request i goes to server i % k, or the next free server after it (wrapping
// around), or is dropped if all k are busy. Returns the servers that handled
// the most requests, in increasing order.
std::vector<int> busiestServers(int k, std::vector<int>& arrival, std::vector<int>& load);
