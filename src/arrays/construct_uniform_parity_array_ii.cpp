#include "arrays/construct_uniform_parity_array_ii.hpp"
#include <algorithm>

bool uniformArrayII(std::vector<int>& nums1) {
    // An odd element can only be made even by subtracting a smaller odd one,
    // and an even element can only be made odd by subtracting a smaller odd
    // one. So, scanning in ascending order:
    //   all-even is possible only if there is no odd element at all;
    //   all-odd is possible only if no even element appears before the first
    //   odd one, i.e. the smallest element is odd (or there are no evens).
    std::sort(nums1.begin(), nums1.end());

    bool seen_odd = false, odd_all = true, even_all = true;
    int n = static_cast<int>(nums1.size());
    for (int i = 0; i < n; ++i) {
        if (nums1[i] % 2) {
            if (!seen_odd) {
                even_all = false;
                seen_odd = true;
            }
        } else if (!seen_odd) {
            // An even element with no smaller odd element to subtract.
            odd_all = false;
        }
    }

    return odd_all || even_all;
}
