#pragma once

#include <string>

// Returns the largest num-digit number whose digits add up to sum and whose
// sum of squared digits is maximal, or "" if no such number exists.
// Time: O(num), Space: O(num)
std::string maxSumOfSquares(int num, int sum);
