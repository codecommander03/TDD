#pragma once

#include <string>
#include <vector>

// Returns every distinct valid string reachable from s by removing the
// minimum number of parentheses, in any order.
std::vector<std::string> removeInvalidParentheses(const std::string& s);
