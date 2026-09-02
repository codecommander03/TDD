#include <gtest/gtest.h>
#include "arrays/construct_uniform_parity_array_i.hpp"

TEST(ConstructUniformParityArrayI, Example1) {
    // Statement example: nums2 = [2 - 3, 3] = [-1, 3], all odd.
    std::vector<int> nums1 = {2, 3};
    EXPECT_TRUE(uniformArray(nums1));
}

TEST(ConstructUniformParityArrayI, Example2) {
    // Statement example: nums2 = [4, 6] is already all even.
    std::vector<int> nums1 = {4, 6};
    EXPECT_TRUE(uniformArray(nums1));
}

TEST(ConstructUniformParityArrayI, SingleElement) {
    // No j != i exists, but a one-element array is trivially all odd.
    std::vector<int> nums1 = {7};
    EXPECT_TRUE(uniformArray(nums1));
}

TEST(ConstructUniformParityArrayI, AllOddAlready) {
    // Keep nums2[i] = nums1[i]; every element is already odd.
    std::vector<int> nums1 = {1, 3, 5, 9};
    EXPECT_TRUE(uniformArray(nums1));
}

TEST(ConstructUniformParityArrayI, AllEvenAlready) {
    // Keep nums2[i] = nums1[i]; every element is already even.
    std::vector<int> nums1 = {2, 8, 100};
    EXPECT_TRUE(uniformArray(nums1));
}

TEST(ConstructUniformParityArrayI, MixedParity) {
    // Subtract the odd 5 from each even element:
    // nums2 = [4 - 5, 5, 6 - 5, 7] = [-1, 5, 1, 7], all odd.
    std::vector<int> nums1 = {4, 5, 6, 7};
    EXPECT_TRUE(uniformArray(nums1));
}
