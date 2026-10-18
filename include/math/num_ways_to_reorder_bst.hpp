#pragma once

#include <vector>

// nums is a permutation of 1..n inserted in order into an empty BST. Returns the
// number of other orderings of nums that build the same BST, modulo 1e9 + 7.
// Time: O(n + log MOD), Space: O(n)
int numOfWays(const std::vector<int>& nums);
