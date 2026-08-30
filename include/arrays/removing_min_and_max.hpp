#pragma once

#include <vector>

// Each deletion takes an element off the front or the back; returns the fewest
// deletions that remove both the minimum and the maximum of nums, whose values
// are all distinct.
int minimumDeletions(const std::vector<int>& nums);
