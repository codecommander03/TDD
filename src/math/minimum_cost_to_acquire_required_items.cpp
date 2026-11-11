#include "math/minimum_cost_to_acquire_required_items.hpp"
#include <algorithm>

long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
    long long res = 0;
    // The shared part: one of each, bought separately or as a combined item
    int cost = std::min(cost1 + cost2, costBoth);
    res += 1LL * cost * std::min(need1, need2);
    // The leftover of one type: single item, or a combined item if that is cheaper
    if (need2 > need1) res += 1LL * (need2 - need1) * std::min(cost2, costBoth);
    else res += 1LL * (need1 - need2) * std::min(cost1, costBoth);
    return res;
}
