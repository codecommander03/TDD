#include "arrays/find_x_value_of_array_i.hpp"

std::vector<long long> resultArray(std::vector<int>& nums, int k) {
    int n = static_cast<int>(nums.size());
    // f[j] counts the subarrays ending at the current index whose product is
    // j modulo k; k <= 5 by the constraints, so five slots always suffice.
    std::vector<long long> f(5), res(k);

    for (int i = 0; i < n; i++) {
        nums[i] %= k;
        std::vector<int> curr(k);
        // The one-element subarray [nums[i]].
        curr[nums[i]] = 1;

        // Every subarray ending at i - 1 extends by nums[i], which multiplies
        // its residue.
        for (int j = 0; j < k; j++) curr[(j * nums[i]) % k] += f[j];
        for (int j = 0; j < k; j++) {
            f[j] = curr[j];
            res[j] += f[j];
        }
    }
    return res;
}
