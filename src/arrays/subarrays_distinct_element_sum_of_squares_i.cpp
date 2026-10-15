#include "arrays/subarrays_distinct_element_sum_of_squares_i.hpp"
#include <set>

int sumCounts(const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size()), res = 0;
    for (int l = 1; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            std::set<int> s(nums.begin() + i, nums.begin() + i + l);
            int d = static_cast<int>(s.size());
            res += d * d;
        }
    }
    return res;
}
