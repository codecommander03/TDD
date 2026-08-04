#include <gtest/gtest.h>
#include "arrays/find_missing_elements.hpp"

TEST(FindMissingElements, SingleMissingValue) {
    std::vector<int> nums = {1, 4, 2, 5};
    EXPECT_EQ(findMissingElements(nums), (std::vector<int>{3}));
}

TEST(FindMissingElements, NoMissingValues) {
    std::vector<int> nums = {7, 8, 6, 9};
    EXPECT_TRUE(findMissingElements(nums).empty());
}

TEST(FindMissingElements, MultipleMissingValues) {
    std::vector<int> nums = {5, 1};
    EXPECT_EQ(findMissingElements(nums), (std::vector<int>{2, 3, 4}));
}

TEST(FindMissingElements, UnorderedWithGaps) {
    std::vector<int> nums = {9, 6, 7, 8};
    EXPECT_TRUE(findMissingElements(nums).empty());
}