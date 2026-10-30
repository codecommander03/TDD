#include <gtest/gtest.h>
#include "graphs/shortest_path_with_at_most_k_consecutive_identical_characters.hpp"

// Example 1: 0->1->2 gives "aab" (run 2 > k), so only the direct 0->2 edge (3) is valid.
TEST(ShortestPathWithAtMostKConsecutiveIdenticalCharacters, Example1_CheapPathTooLongRun) {
    std::vector<std::vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {0, 2, 3}};
    EXPECT_EQ(shortestPath(3, edges, "aab", 1), 3);
}

// Example 2: with k = 2, "aab" is allowed, so 0->1->2 costs 1 + 1 = 2.
TEST(ShortestPathWithAtMostKConsecutiveIdenticalCharacters, Example2_CheapPathAllowed) {
    std::vector<std::vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {0, 2, 3}};
    EXPECT_EQ(shortestPath(3, edges, "aab", 2), 2);
}

// Example 3: the only path spells "aaa" (run 3 > 2).
TEST(ShortestPathWithAtMostKConsecutiveIdenticalCharacters, Example3_NoValidPath) {
    std::vector<std::vector<int>> edges = {{0, 1, 1}, {1, 2, 1}};
    EXPECT_EQ(shortestPath(3, edges, "aaa", 2), -1);
}

// Single node: start is the target, path "a" has run 1 <= k, cost 0.
TEST(ShortestPathWithAtMostKConsecutiveIdenticalCharacters, SingleNode) {
    std::vector<std::vector<int>> edges = {};
    EXPECT_EQ(shortestPath(1, edges, "a", 1), 0);
}

// Edges are directed: only 1->0 exists, so node 1 is unreachable from 0.
TEST(ShortestPathWithAtMostKConsecutiveIdenticalCharacters, DirectedEdgeWrongWay) {
    std::vector<std::vector<int>> edges = {{1, 0, 1}};
    EXPECT_EQ(shortestPath(2, edges, "ab", 1), -1);
}

// Reaching node 2 cheaply (0->1->2, cost 2) leaves a run of 3 'a's (invalid at k = 2);
// the pricier arrival 0->2 (cost 5, run 2) must still be explored. 0->2->3 = "aab", cost 6.
TEST(ShortestPathWithAtMostKConsecutiveIdenticalCharacters, CheaperArrivalDoesNotBlockValidOne) {
    std::vector<std::vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {0, 2, 5}, {2, 3, 1}};
    EXPECT_EQ(shortestPath(4, edges, "aaab", 2), 6);
}
