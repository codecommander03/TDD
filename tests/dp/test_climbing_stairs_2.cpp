#include <gtest/gtest.h>
#include "dp/climbing_stairs_2.hpp"

// LeetCode Example 1: 0 -> 1 -> 2 -> 4 costs (1 + 1) + (2 + 1) + (4 + 4) = 13
TEST(ClimbingStairsII, Example1) {
    std::vector<int> costs = {1, 2, 3, 4};
    EXPECT_EQ(climbStairs(4, costs), 13);
}

// LeetCode Example 2: 0 -> 2 -> 4 costs (1 + 4) + (2 + 4) = 11
TEST(ClimbingStairsII, Example2) {
    std::vector<int> costs = {5, 1, 6, 2};
    EXPECT_EQ(climbStairs(4, costs), 11);
}

// LeetCode Example 3: 0 -> 3 costs 3 + 9 = 12
TEST(ClimbingStairsII, Example3) {
    std::vector<int> costs = {9, 8, 3};
    EXPECT_EQ(climbStairs(3, costs), 12);
}

// One step: 0 -> 1 costs 7 + 1 = 8
TEST(ClimbingStairsII, SingleStep) {
    std::vector<int> costs = {7};
    EXPECT_EQ(climbStairs(1, costs), 8);
}

// Two cheap steps: 0 -> 1 -> 2 costs (1 + 1) + (1 + 1) = 4, beating 0 -> 2 at 1 + 4 = 5
TEST(ClimbingStairsII, SmallStepsBeatJump) {
    std::vector<int> costs = {1, 1};
    EXPECT_EQ(climbStairs(2, costs), 4);
}

// Expensive middle steps: jumping straight 0 -> 3 costs 1 + 9 = 10
TEST(ClimbingStairsII, JumpOverExpensiveSteps) {
    std::vector<int> costs = {100, 100, 1};
    EXPECT_EQ(climbStairs(3, costs), 10);
}
