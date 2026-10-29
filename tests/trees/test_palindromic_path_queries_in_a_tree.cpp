#include <gtest/gtest.h>
#include "trees/palindromic_path_queries_in_a_tree.hpp"

// LeetCode Example 1: path 0-1-2 is "aac" -> "aca" (true); after node 1
// becomes 'b' it is "abc" (false)
TEST(PalindromicPathQueriesInATree, Example1) {
    std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}};
    std::vector<std::string> queries = {"query 0 2", "update 1 b", "query 0 2"};
    std::vector<bool> expected = {true, false};
    EXPECT_EQ(palindromePath(3, edges, "aac", queries), expected);
}

// LeetCode Example 2: star centred on 0. "bac" (false); node 0 -> 'b';
// "cba" (false); node 3 -> 'a' (unchanged); "bba" -> "bab" (true)
TEST(PalindromicPathQueriesInATree, Example2) {
    std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}};
    std::vector<std::string> queries = {"query 1 2", "update 0 b", "query 2 3", "update 3 a", "query 1 3"};
    std::vector<bool> expected = {false, false, true};
    EXPECT_EQ(palindromePath(4, edges, "abca", queries), expected);
}

// Single node: the path is one letter, always a palindrome
TEST(PalindromicPathQueriesInATree, SingleNode) {
    std::vector<std::vector<int>> edges = {};
    std::vector<std::string> queries = {"query 0 0", "update 0 z", "query 0 0"};
    std::vector<bool> expected = {true, true};
    EXPECT_EQ(palindromePath(1, edges, "a", queries), expected);
}

// Tree 0-1, 1-2, 1-3, 3-4 with letters z a b c b. Paths 2-4 meet at node 1,
// not the root, and the root update must reach the whole tree.
//   query 2 4: 2-1-3-4 = b a c b, a and c odd      -> false
//   update 3 a: letters z a b a b
//   query 2 4: b a a b                             -> true
//   query 0 4: 0-1-3-4 = z a a b, z and b odd      -> false
//   update 0 b: letters b a b a b
//   query 0 4: b a a b                             -> true
//   query 4 4: b                                   -> true
TEST(PalindromicPathQueriesInATree, LcaBelowRoot) {
    std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    std::vector<std::string> queries = {"query 2 4", "update 3 a", "query 2 4", "query 0 4",
                                        "update 0 b", "query 0 4", "query 4 4"};
    std::vector<bool> expected = {false, true, false, true, true};
    EXPECT_EQ(palindromePath(5, edges, "zabcb", queries), expected);
}

// Chain 0-1-...-11 with letters aaaaaaaaaabb, so node indices have two digits.
//   query 10 11: b b                   -> true
//   update 10 c: node 10 is now 'c'
//   query 9 11: a c b                  -> false
//   update 11 c: node 11 is now 'c'
//   query 10 11: c c                   -> true
TEST(PalindromicPathQueriesInATree, MultiDigitNodes) {
    std::vector<std::vector<int>> edges;
    for (int i = 0; i + 1 < 12; i++) edges.push_back({i, i + 1});
    std::vector<std::string> queries = {"query 10 11", "update 10 c", "query 9 11", "update 11 c", "query 10 11"};
    std::vector<bool> expected = {true, false, true};
    EXPECT_EQ(palindromePath(12, edges, "aaaaaaaaaabb", queries), expected);
}
