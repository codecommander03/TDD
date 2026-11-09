#include <gtest/gtest.h>
#include "arrays/find_servers_that_handled_most_requests.hpp"

// LeetCode Example 1: requests go to 0, 1, 2; at t=4 server 0 is busy so
// server 1 (free at 4) takes it; at t=5 all are busy and it is dropped.
// Handled {1, 2, 1} -> {1}
TEST(FindServersThatHandledMostRequests, Example1) {
    std::vector<int> arrival = {1, 2, 3, 4, 5};
    std::vector<int> load = {5, 2, 3, 3, 3};
    EXPECT_EQ(busiestServers(3, arrival, load), (std::vector<int>{1}));
}

// LeetCode Example 2: requests go to 0, 1, 2, then 0 again (free at 2).
// Handled {2, 1, 1} -> {0}
TEST(FindServersThatHandledMostRequests, Example2) {
    std::vector<int> arrival = {1, 2, 3, 4};
    std::vector<int> load = {1, 2, 1, 2};
    EXPECT_EQ(busiestServers(3, arrival, load), (std::vector<int>{0}));
}

// LeetCode Example 3: one request each -> all three tie
TEST(FindServersThatHandledMostRequests, Example3) {
    std::vector<int> arrival = {1, 2, 3};
    std::vector<int> load = {10, 12, 11};
    EXPECT_EQ(busiestServers(3, arrival, load), (std::vector<int>{0, 1, 2}));
}

// k = 1: free exactly at arrival counts (t=2), then busy until 7 so t=3 is dropped
TEST(FindServersThatHandledMostRequests, SingleServer) {
    std::vector<int> arrival = {1, 2, 3};
    std::vector<int> load = {1, 5, 1};
    EXPECT_EQ(busiestServers(1, arrival, load), (std::vector<int>{0}));
}

// Skips forward: request 3 prefers server 0 (busy until 11), so server 1
// (free at 3) takes it. Handled {1, 2, 1} -> {1}
TEST(FindServersThatHandledMostRequests, SkipsToNextFree) {
    std::vector<int> arrival = {1, 2, 3, 4};
    std::vector<int> load = {10, 1, 10, 10};
    EXPECT_EQ(busiestServers(3, arrival, load), (std::vector<int>{1}));
}

// Wraps around: servers 1 and 2 stay busy, so requests 4 (prefers 1) and
// 5 (prefers 2) both wrap to server 0. Handled {4, 1, 1} -> {0}
TEST(FindServersThatHandledMostRequests, WrapsAround) {
    std::vector<int> arrival = {1, 2, 3, 4, 5, 6};
    std::vector<int> load = {1, 100, 100, 1, 1, 1};
    EXPECT_EQ(busiestServers(3, arrival, load), (std::vector<int>{0}));
}
