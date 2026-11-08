#include <gtest/gtest.h>
#include "arrays/process_tasks_using_servers.hpp"

// LeetCode Example 1: server 2 (weight 2) takes tasks at 0, 1, 3 and 5;
// at 2 it is busy so server 0 takes it; at 4 only server 1 is free
TEST(ProcessTasksUsingServers, Example1) {
    std::vector<int> servers = {3, 3, 2};
    std::vector<int> tasks = {1, 2, 3, 2, 1, 2};
    EXPECT_EQ(assignTasks(servers, tasks), (std::vector<int>{2, 2, 0, 2, 1, 2}));
}

// LeetCode Example 2: weights by index 1 < 4 < 3 < 2 < 0; lightest free server each second
TEST(ProcessTasksUsingServers, Example2) {
    std::vector<int> servers = {5, 1, 4, 3, 2};
    std::vector<int> tasks = {2, 1, 2, 4, 5, 2, 1};
    EXPECT_EQ(assignTasks(servers, tasks), (std::vector<int>{1, 4, 1, 4, 1, 3, 2}));
}

// One server, still busy at 1 (until 3): task 1 waits for it -> {0, 0}
TEST(ProcessTasksUsingServers, SingleServerWaits) {
    std::vector<int> servers = {1};
    std::vector<int> tasks = {3, 1};
    EXPECT_EQ(assignTasks(servers, tasks), (std::vector<int>{0, 0}));
}

// Equal weights tie on index: server 0 is busy at 1, so server 1 -> {0, 1}
TEST(ProcessTasksUsingServers, EqualWeightsTieOnIndex) {
    std::vector<int> servers = {1, 1};
    std::vector<int> tasks = {2, 1};
    EXPECT_EQ(assignTasks(servers, tasks), (std::vector<int>{0, 1}));
}

// At second 2 both servers are busy until 3; the lighter one (index 1) wins
TEST(ProcessTasksUsingServers, AllBusyTieOnWeight) {
    std::vector<int> servers = {2, 1};
    std::vector<int> tasks = {3, 2, 1};
    EXPECT_EQ(assignTasks(servers, tasks), (std::vector<int>{1, 0, 1}));
}

// At second 2 both are busy; server 0 frees at 5, server 1 at 6 -> server 0
// takes it at 5
TEST(ProcessTasksUsingServers, AllBusyEarliestFinishWins) {
    std::vector<int> servers = {1, 2};
    std::vector<int> tasks = {5, 5, 1};
    EXPECT_EQ(assignTasks(servers, tasks), (std::vector<int>{0, 1, 0}));
}
