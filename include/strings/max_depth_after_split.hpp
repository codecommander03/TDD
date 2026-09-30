#pragma once

#include <string>
#include <vector>

// Splits the valid parentheses string seq into two disjoint valid
// subsequences A and B so that max(depth(A), depth(B)) is as small as
// possible. answer[i] is 0 if seq[i] goes to A and 1 if it goes to B.
std::vector<int> maxDepthAfterSplit(const std::string& seq);
