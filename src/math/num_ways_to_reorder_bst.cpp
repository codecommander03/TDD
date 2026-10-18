#include "math/num_ways_to_reorder_bst.hpp"

int numOfWays(const std::vector<int>& nums) {
    const long long MOD = 1e9 + 7;
    auto power = [](long long b, long long e, long long m) {
        long long r = 1;
        for (b %= m; e; e >>= 1, b = b * b % m)
            if (e & 1) r = r * b % m;
        return r;
    };

    int n = static_cast<int>(nums.size());
    std::vector<int> born(n + 2, -1);  // insertion time of each value; the walls 0 and n + 1 come before everything
    for (int i = 0; i < n; ++i) born[nums[i]] = i;

    long long fact = 1, sizes = 1;  // n! and the product of subtree sizes, mod p
    for (int k = 2; k <= n; ++k) fact = fact * k % MOD;
    std::vector<int> stack = {0};  // values with increasing insertion times
    for (int v = 1; v <= n + 1; ++v) {
        while (born[stack.back()] > born[v]) {  // v is the right wall of the value on top
            stack.pop_back();
            sizes = sizes * (v - stack.back() - 1) % MOD;  // and the value below it is the left wall
        }
        stack.push_back(v);
    }
    return static_cast<int>((fact * power(sizes, MOD - 2, MOD) - 1 + MOD) % MOD);  // n! / sizes - 1
}
