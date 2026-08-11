#include <gtest/gtest.h>
#include "arrays/missing_integer.hpp"

TEST(MissingInteger, BasicPrefixSum) {
    std::vector<int> nums = {1, 2, 3, 2, 5};
    EXPECT_EQ(missingInteger(nums), 6);
}

TEST(MissingInteger, NoConsecutivePrefix) {
    std::vector<int> nums = {3, 4, 5, 1, 12, 14, 13};
    EXPECT_EQ(missingInteger(nums), 15);
}

TEST(MissingInteger, SingleElement) {
    std::vector<int> nums = {7};
    EXPECT_EQ(missingInteger(nums), 8);
}

TEST(MissingInteger, EntireArrayConsecutive) {
    std::vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(missingInteger(nums), 10);
}