#include "arrays/min_swaps_to_sort_by_digit_sum.hpp"
#include <algorithm>
#include <map>

int minSwaps(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size()), res = 0;
    auto s = [](int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    };
    std::map<int, int> m;
    for (int i = 0; i < n; i++) m[nums[i]] = i;
    std::vector<int> v = nums;
    std::sort(std::begin(v), std::end(v), [&s](int a, int b) {
        if (s(a) != s(b)) return s(a) < s(b);
        return a < b;
    });
    for (int i = 0; i < n; i++) {
        if (v[i] == nums[i]) continue;
        res++;
        int pos = m[v[i]];
        nums[pos] = nums[i];
        m[nums[i]] = pos;
        m[v[i]] = i;
        v[i] = nums[i];
    }
    return res;
}
