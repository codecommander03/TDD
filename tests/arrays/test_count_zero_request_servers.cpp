#include <gtest/gtest.h>
#include "arrays/count_zero_request_servers.hpp"

// LeetCode Example 1: [5,10] sees servers 1 and 2 -> 1 idle;
// [6,11] sees only server 2 -> 2 idle
TEST(CountZeroRequestServers, Example1) {
    std::vector<std::vector<int>> logs = {{1, 3}, {2, 6}, {1, 5}};
    std::vector<int> queries = {10, 11};
    EXPECT_EQ(countServers(3, logs, 5, queries), (std::vector<int>{1, 2}));
}

// LeetCode Example 2: [1,3] sees all three servers -> 0 idle;
// [2,4] sees servers 1 and 2 -> 1 idle
TEST(CountZeroRequestServers, Example2) {
    std::vector<std::vector<int>> logs = {{2, 4}, {2, 1}, {1, 2}, {3, 1}};
    std::vector<int> queries = {3, 4};
    EXPECT_EQ(countServers(3, logs, 2, queries), (std::vector<int>{0, 1}));
}

// No log falls in [4,5] -> both servers idle
TEST(CountZeroRequestServers, EmptyWindow) {
    std::vector<std::vector<int>> logs = {{1, 10}};
    std::vector<int> queries = {5};
    EXPECT_EQ(countServers(2, logs, 1, queries), (std::vector<int>{2}));
}

// The interval is inclusive: time 3 is in [3,5] (1 idle) but not in [4,6] (2 idle)
TEST(CountZeroRequestServers, InclusiveLeftEdge) {
    std::vector<std::vector<int>> logs = {{1, 3}};
    std::vector<int> queries = {5, 6};
    EXPECT_EQ(countServers(2, logs, 2, queries), (std::vector<int>{1, 2}));
}

// Unsorted queries keep their order: [4,5] sees server 2, [0,1] sees server 1,
// [2,3] sees nobody -> {1, 1, 2}
TEST(CountZeroRequestServers, UnsortedQueries) {
    std::vector<std::vector<int>> logs = {{1, 1}, {2, 5}};
    std::vector<int> queries = {5, 1, 3};
    EXPECT_EQ(countServers(2, logs, 1, queries), (std::vector<int>{1, 1, 2}));
}

// Repeated requests from one server count it once: [1,6] sees server 1 -> 1 idle
TEST(CountZeroRequestServers, RepeatedServer) {
    std::vector<std::vector<int>> logs = {{1, 2}, {1, 3}};
    std::vector<int> queries = {6};
    EXPECT_EQ(countServers(2, logs, 5, queries), (std::vector<int>{1}));
}
