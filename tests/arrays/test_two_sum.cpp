#include <gtest/gtest.h>
#include "arrays/two_sum.hpp"

TEST(TwoSum, FindsBasicPair) {
    std::vector<int> nums = {2, 7, 11, 15};
    auto result = twoSum(nums, 9);
    EXPECT_EQ(result, (std::vector<int>{0, 1}));
}

TEST(TwoSum, HandlesNegativeNumbers) {
    std::vector<int> nums = {-3, 4, 3, 90};
    auto result = twoSum(nums, 0);
    EXPECT_EQ(result, (std::vector<int>{0, 2}));
}

TEST(TwoSum, ReturnsEmptyWhenNoSolution) {
    std::vector<int> nums = {1, 2, 3};
    auto result = twoSum(nums, 100);
    EXPECT_TRUE(result.empty());
}

TEST(TwoSum, HandlesDuplicateValues) {
    std::vector<int> nums = {3, 3};
    auto result = twoSum(nums, 6);
    EXPECT_EQ(result, (std::vector<int>{0, 1}));
}