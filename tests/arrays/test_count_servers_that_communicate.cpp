#include <gtest/gtest.h>
#include "arrays/count_servers_that_communicate.hpp"

// LeetCode Example 1: the two servers share no row or column -> 0
TEST(CountServersThatCommunicate, Example1) {
    std::vector<std::vector<int>> grid = {{1, 0}, {0, 1}};
    EXPECT_EQ(countServers(grid), 0);
}

// LeetCode Example 2: (0,0)-(1,0) share column 0, (1,0)-(1,1) share row 1 -> 3
TEST(CountServersThatCommunicate, Example2) {
    std::vector<std::vector<int>> grid = {{1, 0}, {1, 1}};
    EXPECT_EQ(countServers(grid), 3);
}

// LeetCode Example 3: two in row 0, two in column 2; (3,3) is alone -> 4
TEST(CountServersThatCommunicate, Example3) {
    std::vector<std::vector<int>> grid = {
        {1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    EXPECT_EQ(countServers(grid), 4);
}

// A single server has nobody to talk to -> 0
TEST(CountServersThatCommunicate, SingleServer) {
    std::vector<std::vector<int>> grid = {{1}};
    EXPECT_EQ(countServers(grid), 0);
}

// No servers at all -> 0
TEST(CountServersThatCommunicate, NoServers) {
    std::vector<std::vector<int>> grid = {{0, 0}, {0, 0}};
    EXPECT_EQ(countServers(grid), 0);
}

// Full 2x2: every server shares a row and a column -> 4
TEST(CountServersThatCommunicate, AllServers) {
    std::vector<std::vector<int>> grid = {{1, 1}, {1, 1}};
    EXPECT_EQ(countServers(grid), 4);
}

// One row, two servers apart: same row still counts -> 2
TEST(CountServersThatCommunicate, SameRowNotAdjacent) {
    std::vector<std::vector<int>> grid = {{1, 0, 1}};
    EXPECT_EQ(countServers(grid), 2);
}
