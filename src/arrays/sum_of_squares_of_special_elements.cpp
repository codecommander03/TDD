#include "arrays/sum_of_squares_of_special_elements.hpp"

int sumOfSquares(const std::vector<int>& nums) {
    int res = 0, n = static_cast<int>(nums.size());
    for (int i = 0; i < n; i++) {
        // nums[i] is special when its 1-indexed position divides n.
        if (n % (i + 1) == 0) res += nums[i] * nums[i];
    }
    return res;
}
