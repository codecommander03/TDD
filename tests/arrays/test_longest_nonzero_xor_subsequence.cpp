#include <gtest/gtest.h>
#include "arrays/longest_nonzero_xor_subsequence.hpp"

TEST(LongestNonzeroXorSubsequence, Example1) {
    // Example 1: [1,2,3] XORs to 0, so drop one element -> length 2.
    EXPECT_EQ(longestSubsequence({1, 2, 3}), 2);
}

TEST(LongestNonzeroXorSubsequence, Example2) {
    // Example 2: [2,3,4] XORs to 5 (non-zero), so keep all -> length 3.
    EXPECT_EQ(longestSubsequence({2, 3, 4}), 3);
}

TEST(LongestNonzeroXorSubsequence, AllZerosHasNoSubsequence) {
    // No non-zero element exists, so every subsequence XORs to 0.
    EXPECT_EQ(longestSubsequence({0, 0, 0}), 0);
}

TEST(LongestNonzeroXorSubsequence, SingleNonZeroElement) {
    EXPECT_EQ(longestSubsequence({5}), 1);
}

TEST(LongestNonzeroXorSubsequence, WholeXorZeroDropsOne) {
    // [1,1] XORs to 0; taking a single 1 gives XOR 1 -> length 1.
    EXPECT_EQ(longestSubsequence({1, 1}), 1);
}
