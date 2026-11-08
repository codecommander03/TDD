#pragma once
#include <vector>

// Returns how many servers (1-cells) share a row or column with another server.
int countServers(std::vector<std::vector<int>>& grid);
