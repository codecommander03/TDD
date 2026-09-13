#include <gtest/gtest.h>
#include "arrays/image_overlap.hpp"

TEST(ImageOverlap, Example1) {
    // Example 1: img1 has 1s at (0,0), (0,1), (1,1), (2,1); img2 at (1,1),
    // (1,2), (2,2). Shifting img1 right one and down one lines up three of
    // them ((0,0)->(1,1), (0,1)->(1,2), (1,1)->(2,2)).
    std::vector<std::vector<int>> img1 = {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    std::vector<std::vector<int>> img2 = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
    EXPECT_EQ(largestOverlap(img1, img2), 3);
}

TEST(ImageOverlap, Example2SingleOne) {
    // Example 2: both 1x1 grids hold a 1, so they already overlap.
    std::vector<std::vector<int>> img1 = {{1}};
    std::vector<std::vector<int>> img2 = {{1}};
    EXPECT_EQ(largestOverlap(img1, img2), 1);
}

TEST(ImageOverlap, Example3SingleZero) {
    // Example 3: no 1s anywhere -> no overlap is possible.
    std::vector<std::vector<int>> img1 = {{0}};
    std::vector<std::vector<int>> img2 = {{0}};
    EXPECT_EQ(largestOverlap(img1, img2), 0);
}

TEST(ImageOverlap, OneImageAllZeros) {
    // An empty img1 has nothing to translate onto img2's 1s.
    std::vector<std::vector<int>> img1 = {{0, 0}, {0, 0}};
    std::vector<std::vector<int>> img2 = {{1, 1}, {1, 1}};
    EXPECT_EQ(largestOverlap(img1, img2), 0);
}

TEST(ImageOverlap, IdenticalImagesNeedNoShift) {
    // The zero shift already matches both 1s, at (0,0) and (1,1).
    std::vector<std::vector<int>> img1 = {{1, 0}, {0, 1}};
    std::vector<std::vector<int>> img2 = {{1, 0}, {0, 1}};
    EXPECT_EQ(largestOverlap(img1, img2), 2);
}

TEST(ImageOverlap, PureTranslation) {
    // img2 is img1 slid down one row, so that shift aligns both 1s.
    std::vector<std::vector<int>> img1 = {{1, 1}, {0, 0}};
    std::vector<std::vector<int>> img2 = {{0, 0}, {1, 1}};
    EXPECT_EQ(largestOverlap(img1, img2), 2);
}
