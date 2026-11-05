#include <gtest/gtest.h>
#include "arrays/find_the_distance_value.hpp"

// LeetCode Example 1: 4 and 5 are more than 2 from every b; 8 matches 8 -> 2
TEST(FindTheDistanceValue, Example1) {
    std::vector<int> arr1 = {4, 5, 8};
    std::vector<int> arr2 = {10, 9, 1, 8};
    EXPECT_EQ(findTheDistanceValue(arr1, arr2, 2), 2);
}

// LeetCode Example 2: 1 and 2 qualify; 4 is 2 from 6, 3 is 3 from 6 -> 2
TEST(FindTheDistanceValue, Example2) {
    std::vector<int> arr1 = {1, 4, 2, 3};
    std::vector<int> arr2 = {-4, -3, 6, 10, 20, 30};
    EXPECT_EQ(findTheDistanceValue(arr1, arr2, 3), 2);
}

// LeetCode Example 3: only 100 is more than 6 from every b (nearest is 10) -> 1
TEST(FindTheDistanceValue, Example3) {
    std::vector<int> arr1 = {2, 1, 100, 3};
    std::vector<int> arr2 = {-5, -2, 10, -3, 7};
    EXPECT_EQ(findTheDistanceValue(arr1, arr2, 6), 1);
}

// Distance exactly d does not count: |5 - 2| = 3 -> 0
TEST(FindTheDistanceValue, DistanceExactlyD) {
    std::vector<int> arr1 = {5};
    std::vector<int> arr2 = {2};
    EXPECT_EQ(findTheDistanceValue(arr1, arr2, 3), 0);
}

// Distance d + 1 counts: |5 - 1| = 4 > 3 -> 1
TEST(FindTheDistanceValue, DistanceJustOverD) {
    std::vector<int> arr1 = {5};
    std::vector<int> arr2 = {1};
    EXPECT_EQ(findTheDistanceValue(arr1, arr2, 3), 1);
}

// d = 0: only an exact match disqualifies; 1 survives, 2 does not -> 1
TEST(FindTheDistanceValue, ZeroDistance) {
    std::vector<int> arr1 = {1, 2};
    std::vector<int> arr2 = {2};
    EXPECT_EQ(findTheDistanceValue(arr1, arr2, 0), 1);
}

// b larger than every a: 1 and 2 are both more than 1 from 10 -> 2
TEST(FindTheDistanceValue, AllBelowArr2) {
    std::vector<int> arr1 = {1, 2};
    std::vector<int> arr2 = {10};
    EXPECT_EQ(findTheDistanceValue(arr1, arr2, 1), 2);
}
