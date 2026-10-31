#include <gtest/gtest.h>
#include "dp/twisted_mirror_path_count.hpp"

// LeetCode Example 1 -> 5
TEST(TwistedMirrorPathCount, Example1) {
    std::vector<std::vector<int>> grid = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
    EXPECT_EQ(uniquePaths(grid), 5);
}

// LeetCode Example 2: no mirrors, RD and DR -> 2
TEST(TwistedMirrorPathCount, Example2) {
    std::vector<std::vector<int>> grid = {{0, 0}, {0, 0}};
    EXPECT_EQ(uniquePaths(grid), 2);
}

// LeetCode Example 3: only (0,0)->(0,1)M->(1,1)M->(1,2) survives; the path
// down into (1,0)M -> (1,1)M is deflected down out of the grid -> 1
TEST(TwistedMirrorPathCount, Example3) {
    std::vector<std::vector<int>> grid = {{0, 1, 1}, {1, 1, 0}};
    EXPECT_EQ(uniquePaths(grid), 1);
}

// No mirrors in 2x3: plain lattice paths C(3,1) -> 3
TEST(TwistedMirrorPathCount, NoMirrors2x3) {
    std::vector<std::vector<int>> grid = {{0, 0, 0}, {0, 0, 0}};
    EXPECT_EQ(uniquePaths(grid), 3);
}

// No mirrors in 3x3: C(4,2) -> 6
TEST(TwistedMirrorPathCount, NoMirrors3x3) {
    std::vector<std::vector<int>> grid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    EXPECT_EQ(uniquePaths(grid), 6);
}

// Both off-diagonal cells are mirrors: R into (0,1)M deflects down to (1,1),
// D into (1,0)M deflects right to (1,1); both arrive -> 2
TEST(TwistedMirrorPathCount, MirrorsDeflectOntoTarget) {
    std::vector<std::vector<int>> grid = {{0, 1}, {1, 0}};
    EXPECT_EQ(uniquePaths(grid), 2);
}

// 3x2 with mirror at (1,1):
//   R to (0,1), D into (1,1)M -> deflected right out of grid: invalid
//   D to (1,0), R into (1,1)M -> deflected down to (2,1): valid
//   D, D to (2,0), R to (2,1): valid
// -> 2
TEST(TwistedMirrorPathCount, DeflectionOutOfGridDiscarded) {
    std::vector<std::vector<int>> grid = {{0, 0}, {0, 1}, {0, 0}};
    EXPECT_EQ(uniquePaths(grid), 2);
}
