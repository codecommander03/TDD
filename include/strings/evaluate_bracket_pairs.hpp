#pragma once

#include <string>
#include <vector>

// Replaces every bracket pair (key) in s with the value knowledge maps the key
// to, or with "?" when the key is not in knowledge. Brackets are never nested.
std::string evaluate(const std::string& s,
                     std::vector<std::vector<std::string>>& knowledge);
