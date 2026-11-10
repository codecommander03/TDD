#pragma once
#include <vector>

// Climbing from step 0 to step n, a jump from i to j (j - i in 1..3) costs
// costs[j - 1] + (j - i)^2. Returns the minimum total cost to reach step n.
int climbStairs(int n, std::vector<int>& costs);
