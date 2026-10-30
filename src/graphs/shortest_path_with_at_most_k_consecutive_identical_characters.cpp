#include "graphs/shortest_path_with_at_most_k_consecutive_identical_characters.hpp"
#include <functional>
#include <queue>
#include <tuple>
#include <utility>

int shortestPath(int n, std::vector<std::vector<int>>& edges, std::string labels, int k) {
    std::vector<std::vector<std::pair<int, int>>> g(n);
    for (auto& e : edges) {
        g[e[0]].push_back({e[1], e[2]});
    }

    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<>> pq;
    std::vector<std::vector<int>> dist(n, std::vector<int>(k + 1, 1e9));

    pq.push({0, 0, 1});
    dist[0][1] = 0;

    while (!pq.empty()) {
        auto [d, u, cnt] = pq.top();
        pq.pop();

        if (d > dist[u][cnt]) continue;
        if (u == n - 1) return d;

        for (auto& [v, w] : g[u]) {
            int nxt_cnt = (labels[u] == labels[v]) ? cnt + 1 : 1;
            if (nxt_cnt <= k && d + w < dist[v][nxt_cnt]) {
                dist[v][nxt_cnt] = d + w;
                pq.push({d + w, v, nxt_cnt});
            }
        }
    }
    return -1;
}
