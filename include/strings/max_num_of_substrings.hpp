#pragma once

#include <string>
#include <vector>

// Maximum set of non-overlapping substrings of s such that every occurrence of
// a character inside a chosen substring is also inside it; ties on count are
// broken by smallest total length. Returned left to right.
std::vector<std::string> maxNumOfSubstrings(const std::string& s);
