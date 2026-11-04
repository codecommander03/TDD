#include "dp/minimum_operations_to_make_elements_within_k_subarrays_equal.hpp"

#include <algorithm>
#include <climits>
#include <iterator>
#include <numeric>
#include <set>
#include <utility>

namespace {

// Sliding window that tracks the cost of making every element equal to the median
class Window {
    std::multiset<int> s;
    std::multiset<int>::iterator mid;  // the (h+1)-th smallest: everything before it is the low half
    long long low, total;
    int odd;

public:
    Window(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last)
        : s(first, last), odd(static_cast<int>(s.size() & 1)) {
        mid = std::next(s.begin(), s.size() / 2);
        low = std::accumulate(s.begin(), mid, 0LL);
        total = std::accumulate(s.begin(), s.end(), 0LL);
    }

    long long cost() const {  // larger half minus smaller half
        return total - 2 * low - odd * *mid;
    }

    long long slide(int out, int in) {
        s.insert(in);
        if (in < *mid)  // in joins the low half and pushes its largest up
            low += in - *--mid;
        if (out < *mid) {  // out leaves the low half: mid moves down into it
            low += *mid++ - out;
            s.erase(s.find(out));
        } else if (out == *mid) {
            mid = s.erase(mid);
        } else {
            s.erase(s.find(out));
        }
        total += in - out;
        return cost();
    }
};

}  // namespace

long long minOperations(std::vector<int>& nums, int x, int k) {
    int n = static_cast<int>(nums.size());
    Window win(nums.cbegin(), nums.cbegin() + x);
    std::vector<long long> cost{win.cost()};  // cost[i]: ops to equalize nums[i..i+x)
    for (int i = x; i < n; ++i)
        cost.push_back(win.slide(nums[i - x], nums[i]));

    std::vector<long long> best(n + 1);  // best[i]: min ops for the windows placed so far inside nums[0..i)
    for (int j = 0; j < k; ++j) {
        std::vector<long long> layer(n + 1, LLONG_MAX / 2);
        for (int i = x; i <= n; ++i)
            layer[i] = std::min(layer[i - 1], best[i - x] + cost[i - x]);
        best = std::move(layer);
    }
    return best[n];
}
