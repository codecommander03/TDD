#pragma once

#include <string>

// Sum over every character of its reverse alphabet position ('a' = 26 ... 'z' = 1)
// multiplied by its 1-indexed position in s.
int reverseDegree(const std::string& s);
