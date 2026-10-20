#include "arrays/sum_of_sortable_integers.hpp"
#include <algorithm>
#include <numeric>

int sortableIntegers(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());

    std::vector<int> desc(n);  // desc[i]: number of descents nums[j] > nums[j + 1] with j < i
    for (int i = 1; i < n; i++) desc[i] = desc[i - 1] + (nums[i - 1] > nums[i]);
    std::vector<int> premax(n), sufmin(n);
    std::inclusive_scan(nums.begin(), nums.end(), premax.begin(), [](int a, int b) { return std::max(a, b); });  // premax[i]: max of nums[0..i]
    std::inclusive_scan(nums.rbegin(), nums.rend(), sufmin.rbegin(), [](int a, int b) { return std::min(a, b); });  // sufmin[i]: min of nums[i..n-1]
    std::vector<bool> cut(n, true);  // cut[m]: nums[0..m-1] holds exactly the m smallest values
    for (int m = 1; m < n; m++) cut[m] = premax[m - 1] <= sufmin[m];

    auto rotatable = [&](int l, int r) {  // nums[l..r] is a rotated sorted run: at most one cyclic descent
        return desc[r] - desc[l] + (nums[r] > nums[l]) <= 1;
    };
    auto sortable = [&](int k) {  // every block starts at a valid cut and can be rotated into order
        for (int l = 0; l < n; l += k)
            if (!cut[l] || !rotatable(l, l + k - 1)) return false;
        return true;
    };

    int res = 0;
    for (int k = 1; k <= n; k++)
        if (n % k == 0 && sortable(k)) res += k;
    return res;
}
