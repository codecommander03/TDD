#include <gtest/gtest.h>
#include "graph/remove_methods.hpp"

TEST(RemoveMethods, SafeMethodCallsSuspicious_RemovesAll) {
    int n = 4, k = 1;
    std::vector<std::vector<int>> invocations = {{0, 1}, {1, 2}, {3, 2}};
    std::vector<int> expected = {0, 1, 2, 3};
    EXPECT_EQ(remainingMethods(n, k, invocations), expected);
}

TEST(RemoveMethods, OnlySuspiciousRemoved) {
    int n = 5, k = 0;
    std::vector<std::vector<int>> invocations = {{1, 2}, {0, 2}, {0, 1}, {3, 4}};
    std::vector<int> expected = {3, 4};
    EXPECT_EQ(remainingMethods(n, k, invocations), expected);
}

TEST(RemoveMethods, NoInvocations_OnlyKIsSuspicious) {
    int n = 3, k = 2;
    std::vector<std::vector<int>> invocations = {{1, 2}, {0, 1}, {2, 0}};
    std::vector<int> expected = {};
    EXPECT_EQ(remainingMethods(n, k, invocations), expected);
}

TEST(RemoveMethods, DisconnectedGraph_SafePart) {
    int n = 4, k = 0;
    std::vector<std::vector<int>> invocations = {{0, 1}, {1, 2}, {3, 2}};
    std::vector<int> expected = {0, 1, 2, 3};
    EXPECT_EQ(remainingMethods(n, k, invocations), expected);
}