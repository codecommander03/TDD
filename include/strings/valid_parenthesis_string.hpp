#pragma once

#include <string>

// Returns true if s (made of '(', ')' and '*') can be a valid parentheses
// string, where each '*' may act as '(', ')' or the empty string.
bool checkValidString(const std::string& s);
