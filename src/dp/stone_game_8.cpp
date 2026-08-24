#include "dp/stone_game_8.hpp"
#include <algorithm>

int stoneGameVIII(std::vector<int>& stones) {
    int n = static_cast<int>(stones.size());

    // Every move replaces a prefix by its sum, so after any number of moves the
    // row is a suffix of the original preceded by one merged stone. A move that
    // takes the first i + 1 stones scores pre[i], and it hands the opponent the
    // same game starting at index i.
    std::vector<int> pre(n);
    pre[0] = stones[0];
    for (int i = 1; i < n; ++i) pre[i] = pre[i - 1] + stones[i];

    // best = the largest score difference the player to move can force when the
    // first legal move is at index i. Starting at the last index there is only
    // one move left, worth the whole row.
    int best = pre[n - 1];

    // Moving at i scores pre[i] and leaves the opponent a game worth best, so
    // the difference becomes pre[i] - best. Index 0 is never a legal stopping
    // point because at least two stones must be taken on the first move.
    for (int i = n - 2; i > 0; --i) best = std::max(best, pre[i] - best);

    return best;
}
