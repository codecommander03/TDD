#pragma once

#include <string>

// Returns s with the outermost pair of parentheses removed from every
// primitive valid part of its decomposition.
std::string removeOuterParentheses(const std::string& s);
