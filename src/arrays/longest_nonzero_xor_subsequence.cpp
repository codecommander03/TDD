#include "arrays/longest_nonzero_xor_subsequence.hpp"

int longestSubsequence(const std::vector<int>& nums) {
    int totalXor = 0;
    bool hasNonZero = false;

    for (int value : nums) {
        totalXor ^= value;
        if (value != 0) hasNonZero = true;
    }

    // No non-zero element: every subsequence XORs to 0, so none qualifies.
    if (!hasNonZero) return 0;

    // If the whole array already XORs to non-zero, keep all of it.
    // Otherwise drop a single non-zero element to break the zero XOR.
    return static_cast<int>(nums.size()) - (totalXor == 0 ? 1 : 0);
}
