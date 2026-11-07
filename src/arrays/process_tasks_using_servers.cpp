#include "arrays/process_tasks_using_servers.hpp"
#include <algorithm>
#include <functional>
#include <queue>
#include <tuple>
#include <utility>

namespace {

struct Server {
    long long at;  // the second it frees up; 0 while free, so free servers sort by weight, then index
    int weight, index;

    bool operator>(const Server& o) const {
        return std::tie(at, weight, index) > std::tie(o.at, o.weight, o.index);
    }
};

using MinHeap = std::priority_queue<Server, std::vector<Server>, std::greater<>>;

}  // namespace

std::vector<int> assignTasks(std::vector<int>& servers, std::vector<int>& tasks) {
    std::vector<Server> all;
    for (int i = 0; i < static_cast<int>(servers.size()); ++i) all.push_back({0, servers[i], i});
    MinHeap free(std::greater<>{}, std::move(all));

    MinHeap busy;
    std::vector<int> ans;
    for (int s = 0; s < static_cast<int>(tasks.size()); ++s) {
        while (!busy.empty() && busy.top().at <= s) {  // done by second s
            Server done = busy.top();
            busy.pop();
            free.push({0, done.weight, done.index});
        }
        MinHeap& from = free.empty() ? busy : free;  // none free: the first to finish takes it
        Server next = from.top();
        from.pop();
        busy.push({std::max<long long>(next.at, s) + tasks[s], next.weight, next.index});
        ans.push_back(next.index);
    }

    return ans;
}
