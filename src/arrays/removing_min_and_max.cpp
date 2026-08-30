#include "arrays/removing_min_and_max.hpp"

#include <algorithm>

int minimumDeletions(const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    int a = static_cast<int>(std::min_element(nums.begin(), nums.end()) - nums.begin());
    int b = static_cast<int>(std::max_element(nums.begin(), nums.end()) - nums.begin());
    if (a > b) std::swap(a, b);

    // Deletions only ever eat a prefix and a suffix, so the two targets can be
    // reached in exactly three ways: sweep the front far enough to pass the
    // later index, sweep the back far enough to pass the earlier one, or take
    // the earlier one from the front and the later one from the back.
    return std::min({b + 1, n - a, (a + 1) + (n - b)});
}
