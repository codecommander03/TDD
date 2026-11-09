#include "arrays/find_servers_that_handled_most_requests.hpp"
#include <algorithm>
#include <functional>
#include <numeric>
#include <queue>
#include <tuple>
#include <utility>

namespace {

struct Job {
    int at;  // the time its server frees up
    int server;

    bool operator>(const Job& o) const { return std::tie(at, server) > std::tie(o.at, o.server); }
};

template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<>>;

}  // namespace

std::vector<int> busiestServers(int k, std::vector<int>& arrival, std::vector<int>& load) {
    std::vector<int> turns(k);
    std::iota(turns.begin(), turns.end(), 0);  // at request 0, server x's next turn is x
    MinHeap<int> free(std::greater<>{}, std::move(turns));  // each free server, keyed by its next turn

    MinHeap<Job> busy;
    std::vector<int> handled(k);
    for (int i = 0; i < static_cast<int>(arrival.size()); ++i) {
        while (!busy.empty() && busy.top().at <= arrival[i]) {  // done by the arrival
            int x = busy.top().server;
            busy.pop();
            free.push(i + (x - i % k + k) % k);  // its first turn from i on
        }
        if (free.empty()) continue;  // none free: the request is dropped
        int x = free.top() % k;
        free.pop();
        busy.push({arrival[i] + load[i], x});
        ++handled[x];
    }

    int most = *std::max_element(handled.begin(), handled.end());
    std::vector<int> ans;
    for (int x = 0; x < k; ++x)
        if (handled[x] == most) ans.push_back(x);
    return ans;
}
