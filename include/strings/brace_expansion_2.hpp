#pragma once

#include <string>
#include <vector>

// Expands the grammar where {e1,e2,...} is a union and adjacency is
// concatenation. Returns the distinct words in sorted order.
std::vector<std::string> braceExpansionII(const std::string& expression);
