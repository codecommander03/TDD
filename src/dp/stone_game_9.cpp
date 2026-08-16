#include "dp/stone_game_9.hpp"
#include <cstdlib>

bool stoneGameIX(std::vector<int>& stones) {
    // Only remainders mod 3 matter for divisibility of the running sum.
    std::vector<int> cnt(3, 0);
    for (int s : stones) cnt[s % 3]++;

    // Even count of 0-mod-3 stones: Alice wins iff both a 1-mod-3 and a
    // 2-mod-3 stone exist to work with. Odd count flips the parity, and
    // Alice then needs the 1s and 2s to differ by more than 2.
    if (cnt[0] % 2 == 0) {
        return cnt[1] > 0 && cnt[2] > 0;
    }
    return std::abs(cnt[1] - cnt[2]) > 2;
}
