#pragma once

#include <string>

// s and target are the same length; returns "" when no permutation of s is
// strictly greater than target.
std::string lexGreaterPermutation(const std::string& s, const std::string& target);
