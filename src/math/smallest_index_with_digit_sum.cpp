#include "math/smallest_index_with_digit_sum.hpp"
#include <string>

int smallestIndex(const std::vector<int>& nums) {
    auto sum = [](std::string s) {
        int ans = 0;
        for (char c : s) ans += c - '0';
        return ans;
    };

    // Scanning left to right returns the smallest qualifying index first.
    int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; i++) {
        if (sum(std::to_string(nums[i])) == i) return i;
    }
    return -1;
}
