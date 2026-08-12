#include <gtest/gtest.h>
#include "arrays/max_subarray_length.hpp"

TEST(MaxSubarrayLength, BasicExample) {
    std::vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    EXPECT_EQ(maxSubarrayLength(nums, 2), 6);
}

TEST(MaxSubarrayLength, KEqualsOne) {
    std::vector<int> nums = {1, 2, 1, 2, 1, 2, 1, 2};
    EXPECT_EQ(maxSubarrayLength(nums, 1), 2);
}

TEST(MaxSubarrayLength, AllUniqueElements) {
    std::vector<int> nums = {1, 2, 2, 1, 3};
    EXPECT_EQ(maxSubarrayLength(nums, 1), 3);
}

TEST(MaxSubarrayLength, KLargerThanAnyFrequency) {
    std::vector<int> nums = {5, 5, 5, 5, 5, 5, 5};
    EXPECT_EQ(maxSubarrayLength(nums, 4), 4);
}