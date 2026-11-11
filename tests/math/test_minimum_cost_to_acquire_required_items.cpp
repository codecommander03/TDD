#include <gtest/gtest.h>
#include "math/minimum_cost_to_acquire_required_items.hpp"

// LeetCode Example 1: combined items cost 1, so 3 of them cover need 3 / 2 -> 3
TEST(MinimumCostToAcquireRequiredItems, Example1) {
    EXPECT_EQ(minimumCost(3, 2, 1, 3, 2), 3);
}

// LeetCode Example 2: 2 pairs at 5 + 4 = 9 each, plus 1 extra type-2 at 4 -> 22
TEST(MinimumCostToAcquireRequiredItems, Example2) {
    EXPECT_EQ(minimumCost(5, 4, 15, 2, 3), 22);
}

// LeetCode Example 3: nothing needed -> 0
TEST(MinimumCostToAcquireRequiredItems, Example3) {
    EXPECT_EQ(minimumCost(5, 4, 15, 0, 0), 0);
}

// Combined item is cheaper than a single even for the leftovers: 4 x 3 = 12
TEST(MinimumCostToAcquireRequiredItems, CombinedCheaperForLeftover) {
    EXPECT_EQ(minimumCost(10, 10, 3, 0, 4), 12);
}

// Singles beat the combined item: 2 pairs at 1 + 1 = 2 each -> 4
TEST(MinimumCostToAcquireRequiredItems, SinglesCheaper) {
    EXPECT_EQ(minimumCost(1, 1, 5, 2, 2), 4);
}

// Leftover of type 1 instead of type 2: 1 combined item at 3 (vs 2 + 4) + 1 extra type-1 at 2 -> 5
TEST(MinimumCostToAcquireRequiredItems, LeftoverTypeOne) {
    EXPECT_EQ(minimumCost(2, 4, 3, 2, 1), 5);
}

// Needs past int range: 10^9 combined items at 10^6 each -> 10^15
TEST(MinimumCostToAcquireRequiredItems, LargeValuesNoOverflow) {
    EXPECT_EQ(minimumCost(1000000, 1000000, 1000000, 1000000000, 1000000000),
              1000000000000000LL);
}
