#include "dp/climbing_stairs_2.hpp"
#include <algorithm>

int climbStairs(int n, std::vector<int>& costs) {
    std::vector<int> v(n + 1, 1e9);  // v[i]: min cost to stand on step i
    v[0] = 0;
    for (int i = 0; i < n; i++) {
        v[i + 1] = std::min(v[i + 1], v[i] + costs[i] + 1);
        if (i + 2 <= n) v[i + 2] = std::min(v[i + 2], v[i] + costs[i + 1] + 4);
        if (i + 3 <= n) v[i + 3] = std::min(v[i + 3], v[i] + costs[i + 2] + 9);
    }
    return v[n];
}
