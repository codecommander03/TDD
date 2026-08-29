#include "arrays/lexicographically_smallest_array.hpp"

#include <algorithm>
#include <numeric>

std::vector<int> lexicographicallySmallestArray(const std::vector<int>& nums, int limit) {
    int n = static_cast<int>(nums.size());

    // Swappability chains: if a and b are swappable and b and c are, then a and
    // c can trade places through b even when they are far apart. Sorting lines
    // those chains up, so a run of sorted values with neighbouring gaps of at
    // most limit is one group whose members can be permuted freely.
    std::vector<int> order(n);
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(), [&](int a, int b) { return nums[a] < nums[b]; });

    // Number the groups and remember where each one starts inside order, which
    // is also where its smallest unused value sits.
    std::vector<int> group(n), next;
    for (int i = 0; i < n; i++) {
        if (i == 0 || nums[order[i]] - nums[order[i - 1]] > limit) next.push_back(i);
        group[order[i]] = static_cast<int>(next.size()) - 1;
    }

    // A position can only ever hold a value from its own group, so filling the
    // array left to right and always handing out that group's smallest value
    // left is the best each position can do without hurting a later one.
    std::vector<int> res(n);
    for (int i = 0; i < n; i++) {
        int g = group[i];
        res[i] = nums[order[next[g]++]];
    }
    return res;
}
