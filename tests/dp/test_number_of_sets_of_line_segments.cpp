#include <gtest/gtest.h>
#include "dp/number_of_sets_of_line_segments.hpp"

TEST(NumberOfSetsOfLineSegments, Example1) {
    // Example 1: with points 0..3 the five pairs are {(0,1),(1,2)},
    // {(0,1),(1,3)}, {(0,1),(2,3)}, {(0,2),(2,3)} and {(1,2),(2,3)}.
    EXPECT_EQ(numberOfSets(4, 2), 5);
}

TEST(NumberOfSetsOfLineSegments, Example2) {
    // Example 2: one segment over points 0..2 -> (0,1), (0,2) or (1,2).
    EXPECT_EQ(numberOfSets(3, 1), 3);
}

TEST(NumberOfSetsOfLineSegments, Example3LargeModulo) {
    // Example 3: the count is C(36,14) = 3,796,297,200, which wraps to
    // 796297179 after the 1e9+7 modulus.
    EXPECT_EQ(numberOfSets(30, 7), 796297179);
}

TEST(NumberOfSetsOfLineSegments, Example4) {
    // Example 4: three segments over points 0..4. Lengths must sum to at most
    // 4, so either all three are length 1 with a single gap in one of four
    // slots, or one is length 2 with no gaps (three placements) -> 7.
    EXPECT_EQ(numberOfSets(5, 3), 7);
}

TEST(NumberOfSetsOfLineSegments, Example5TightFit) {
    // Example 5: points 0..2 fit two segments only as (0,1) and (1,2).
    EXPECT_EQ(numberOfSets(3, 2), 1);
}

TEST(NumberOfSetsOfLineSegments, SmallestBoard) {
    // Two points admit exactly the one segment (0,1)...
    EXPECT_EQ(numberOfSets(2, 1), 1);
    // ...and no room for a second, since segments need distinct endpoints.
    EXPECT_EQ(numberOfSets(2, 2), 0);
}
