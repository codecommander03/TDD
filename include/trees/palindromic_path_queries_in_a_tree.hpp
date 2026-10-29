#pragma once
#include <string>
#include <vector>

// Processes "update u c" (set node u's letter to c) and "query u v" (can the
// letters on the u-v path be rearranged into a palindrome?) in order, returning
// one answer per query.
std::vector<bool> palindromePath(int n, std::vector<std::vector<int>>& edges, const std::string& s,
                                 std::vector<std::string>& queries);
