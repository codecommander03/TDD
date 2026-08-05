#include "graph/remove_methods.hpp"
#include <queue>
#include <set>
#include <numeric>

std::vector<int> remainingMethods(int n, int k, std::vector<std::vector<int>>& invocations) {
    std::vector<std::vector<int>> g(n), rg(n);
    for (auto& i : invocations) {
        int a = i[0], b = i[1];
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    std::set<int> sus;
    std::queue<int> q;
    q.push(k);
    std::vector<bool> vis(n, false);
    vis[k] = true;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        if (sus.count(i)) continue;
        sus.insert(i);
        for (int j : g[i]) {
            if (!vis[j]) {
                vis[j] = true;
                q.push(j);
            }
        }
    }

    vis.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!sus.count(i) || vis[i]) continue;
        q.push(i);
        vis[i] = true;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            vis[f] = true;
            if (!sus.count(f)) {
                std::vector<int> v(n);
                std::iota(v.begin(), v.end(), 0);
                return v;
            }
            for (int x : rg[f]) {
                if (vis[x]) continue;
                vis[x] = true;
                q.push(x);
            }
        }
    }

    std::vector<int> result;
    for (int i = 0; i < n; ++i) {
        if (!sus.count(i)) result.push_back(i);
    }
    return result;
}