#include <gtest/gtest.h>
#include "arrays/rectangle_overlap.hpp"

TEST(RectangleOverlap, Example1) {
    // Example 1: the shared region spans x in (1,2) and y in (1,2) -> area 1.
    std::vector<int> r1 = {0, 0, 2, 2};
    std::vector<int> r2 = {1, 1, 3, 3};
    EXPECT_TRUE(isRectangleOverlap(r1, r2));
}

TEST(RectangleOverlap, Example2EdgeTouch) {
    // Example 2: they meet along the line x = 1, which has zero area.
    std::vector<int> r1 = {0, 0, 1, 1};
    std::vector<int> r2 = {1, 0, 2, 1};
    EXPECT_FALSE(isRectangleOverlap(r1, r2));
}

TEST(RectangleOverlap, Example3Disjoint) {
    // Example 3: fully separated in both axes.
    std::vector<int> r1 = {0, 0, 1, 1};
    std::vector<int> r2 = {2, 2, 3, 3};
    EXPECT_FALSE(isRectangleOverlap(r1, r2));
}

TEST(RectangleOverlap, CornerTouch) {
    // They share only the point (1,1) -> still zero area.
    std::vector<int> r1 = {0, 0, 1, 1};
    std::vector<int> r2 = {1, 1, 2, 2};
    EXPECT_FALSE(isRectangleOverlap(r1, r2));
}

TEST(RectangleOverlap, StackedShareHorizontalEdge) {
    // One sits directly on top of the other, meeting along y = 1.
    std::vector<int> r1 = {0, 0, 2, 1};
    std::vector<int> r2 = {0, 1, 2, 2};
    EXPECT_FALSE(isRectangleOverlap(r1, r2));
}

TEST(RectangleOverlap, OneContainsTheOther) {
    // The small rectangle lies wholly inside the large one.
    std::vector<int> r1 = {0, 0, 10, 10};
    std::vector<int> r2 = {2, 2, 3, 3};
    EXPECT_TRUE(isRectangleOverlap(r1, r2));
}

TEST(RectangleOverlap, IdenticalRectangles) {
    // A rectangle overlaps itself over its whole area.
    std::vector<int> r1 = {0, 0, 2, 2};
    std::vector<int> r2 = {0, 0, 2, 2};
    EXPECT_TRUE(isRectangleOverlap(r1, r2));
}

TEST(RectangleOverlap, NegativeCoordinates) {
    // Overlap across the origin: x in (-1,0) and y in (-1,0).
    std::vector<int> r1 = {-2, -2, 0, 0};
    std::vector<int> r2 = {-1, -1, 1, 1};
    EXPECT_TRUE(isRectangleOverlap(r1, r2));
}
