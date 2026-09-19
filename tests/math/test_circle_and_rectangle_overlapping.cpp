#include <gtest/gtest.h>
#include "math/circle_and_rectangle_overlapping.hpp"

TEST(CircleAndRectangleOverlapping, Example1) {
    // Example 1: the unit circle at the origin reaches x = 1, and the
    // rectangle's left edge runs along x = 1 through y = 0, so (1,0) is shared.
    EXPECT_TRUE(checkOverlap(1, 0, 0, 1, -1, 3, 1));
}

TEST(CircleAndRectangleOverlapping, Example2) {
    // Example 2: the rectangle's top edge is y = -1 while the circle reaches
    // only down to y = 0; the closest point (1,-1) sits 2 away.
    EXPECT_FALSE(checkOverlap(1, 1, 1, 1, -3, 2, -1));
}

TEST(CircleAndRectangleOverlapping, Example3CenterOnCorner) {
    // Example 3: the centre (0,0) is the rectangle's bottom-right corner, so
    // the distance is 0.
    EXPECT_TRUE(checkOverlap(1, 0, 0, -1, 0, 0, 1));
}

TEST(CircleAndRectangleOverlapping, CenterInsideRectangle) {
    // The centre lies well inside, so the circle cannot avoid the rectangle.
    EXPECT_TRUE(checkOverlap(1, 5, 5, 0, 0, 10, 10));
}

TEST(CircleAndRectangleOverlapping, RectangleInsideCircle) {
    // The whole rectangle sits within radius 10 of the origin; its nearest
    // corner (1,1) is only sqrt(2) away.
    EXPECT_TRUE(checkOverlap(10, 0, 0, 1, 1, 2, 2));
}

TEST(CircleAndRectangleOverlapping, TouchesCornerExactly) {
    // Nearest corner (3,4) is exactly 5 from the origin, and a point on the
    // circle still belongs to the circle.
    EXPECT_TRUE(checkOverlap(5, 0, 0, 3, 4, 10, 10));
}

TEST(CircleAndRectangleOverlapping, JustMissesCorner) {
    // Nearest corner (4,4) is sqrt(32) ~ 5.66 from the origin, past radius 5.
    EXPECT_FALSE(checkOverlap(5, 0, 0, 4, 4, 10, 10));
}

TEST(CircleAndRectangleOverlapping, FarApart) {
    // Nearest corner (5,5) is sqrt(50) away from a unit circle.
    EXPECT_FALSE(checkOverlap(1, 0, 0, 5, 5, 6, 6));
}

TEST(CircleAndRectangleOverlapping, NegativeCoordinates) {
    // Centre (-5,-5), nearest corner (-4,-4): distance sqrt(2) < 2.
    EXPECT_TRUE(checkOverlap(2, -5, -5, -4, -4, -1, -1));
}

TEST(CircleAndRectangleOverlapping, AlignedButOutOfReach) {
    // Same y band, so only the x gap matters: the left edge x = 3 is 3 away
    // from the centre, one more than the radius.
    EXPECT_FALSE(checkOverlap(2, 0, 0, 3, -5, 8, 5));
}
