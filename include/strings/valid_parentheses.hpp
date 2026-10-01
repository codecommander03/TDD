#pragma once

#include <string>

// Returns true if every bracket in s ('(', ')', '{', '}', '[', ']') is closed
// by the same type of bracket, in the correct order.
bool isValid(const std::string& s);
