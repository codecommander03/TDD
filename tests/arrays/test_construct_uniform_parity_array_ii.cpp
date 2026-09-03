#include <gtest/gtest.h>
#include "arrays/construct_uniform_parity_array_ii.hpp"

TEST(ConstructUniformParityArrayII, Example1) {
    // Statement example: nums2 = [1, 4 - 1, 7] = [1, 3, 7], all odd.
    std::vector<int> nums1 = {1, 4, 7};
    EXPECT_TRUE(uniformArrayII(nums1));
}

TEST(ConstructUniformParityArrayII, Example2) {
    // Statement example: all-even needs 3 to shed a smaller odd (none exists),
    // all-odd needs 2 to subtract a smaller odd (none exists). Impossible.
    std::vector<int> nums1 = {2, 3};
    EXPECT_FALSE(uniformArrayII(nums1));
}

TEST(ConstructUniformParityArrayII, Example3) {
    // Statement example: nums2 = [4, 6] is already all even.
    std::vector<int> nums1 = {4, 6};
    EXPECT_TRUE(uniformArrayII(nums1));
}

TEST(ConstructUniformParityArrayII, SingleOddElement) {
    // No j != i exists, but a lone odd element is already all odd.
    std::vector<int> nums1 = {5};
    EXPECT_TRUE(uniformArrayII(nums1));
}

TEST(ConstructUniformParityArrayII, SingleEvenElement) {
    // Likewise, a lone even element is already all even.
    std::vector<int> nums1 = {4};
    EXPECT_TRUE(uniformArrayII(nums1));
}

TEST(ConstructUniformParityArrayII, AllOddAlready) {
    // Keep nums2[i] = nums1[i]; every element is already odd.
    std::vector<int> nums1 = {3, 9, 5};
    EXPECT_TRUE(uniformArrayII(nums1));
}

TEST(ConstructUniformParityArrayII, SmallestIsOdd) {
    // 3 is below both evens: nums2 = [3, 4 - 3, 10 - 3] = [3, 1, 7], all odd.
    std::vector<int> nums1 = {3, 4, 10};
    EXPECT_TRUE(uniformArrayII(nums1));
}

TEST(ConstructUniformParityArrayII, SmallestIsEven) {
    // 2 has no smaller odd to subtract, so all-odd fails; 5 has no smaller
    // odd to subtract, so all-even fails too.
    std::vector<int> nums1 = {2, 5, 8};
    EXPECT_FALSE(uniformArrayII(nums1));
}

TEST(ConstructUniformParityArrayII, UnsortedInput) {
    // Same multiset as SmallestIsOdd, given out of order: still all odd.
    std::vector<int> nums1 = {10, 3, 4};
    EXPECT_TRUE(uniformArrayII(nums1));
}
