#pragma once

#include <string>

// Returns the score of balanced string s, where "()" scores 1, AB scores
// A + B, and (A) scores 2 * A.
int scoreOfParentheses(const std::string& s);
