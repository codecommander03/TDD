#include "trees/palindromic_path_queries_in_a_tree.hpp"

#include <algorithm>
#include <cctype>
#include <numeric>

namespace {

struct Tree {  // Euler tour: the subtree of x is tin[x] .. tout[x] - 1; LCA by a sparse table over the DFS order
    std::vector<int> parent, tin, tout, order;  // the root is its own parent; order: the nodes in DFS order
    std::vector<std::vector<int>> first;  // first[k][i]: the earliest parent among order[i .. i + 2^k - 1]

    Tree(int n, std::vector<std::vector<int>>& edges) : parent(n), tin(n), tout(n) {
        std::vector<int> head(n + 1), adj(2 * n);  // the neighbors of x are adj[head[x] .. head[x + 1] - 1]
        for (auto& e : edges) head[e[0] + 1]++, head[e[1] + 1]++;
        std::partial_sum(head.begin(), head.end(), head.begin());
        std::vector<int> pos(head.begin(), head.end() - 1);
        for (auto& e : edges) adj[pos[e[0]]++] = e[1], adj[pos[e[1]]++] = e[0];

        std::vector<int> stack = {0};
        while (!stack.empty()) {  // DFS without recursion; ~x marks the moment x's subtree is done
            int x = stack.back();
            stack.pop_back();
            if (x < 0) {
                tout[~x] = static_cast<int>(order.size());
                continue;
            }
            tin[x] = static_cast<int>(order.size());
            order.push_back(x);
            stack.push_back(~x);
            for (int i = head[x]; i < head[x + 1]; i++)
                if (int y = adj[i]; y != parent[x]) {
                    parent[y] = x;
                    stack.push_back(y);
                }
        }

        first.emplace_back(n);
        for (int i = 0; i < n; i++) first[0][i] = tin[parent[order[i]]];
        for (int k = 1; 1 << k <= n; k++) {
            first.emplace_back(n - (1 << k) + 1);
            for (int i = 0; i + (1 << k) <= n; i++)
                first[k][i] = std::min(first[k - 1][i], first[k - 1][i + (1 << (k - 1))]);
        }
    }

    int lca(int u, int v) {  // the parent that comes first in DFS order among the nodes after u up to v
        if (u == v) return u;
        auto [l, r] = std::minmax(tin[u], tin[v]);
        int k = 0;  // floor(log2(r - l)); std::bit_width is C++20
        while ((2 << k) <= r - l) k++;
        return order[std::min(first[k][l + 1], first[k][r - (1 << k) + 1])];
    }
};

struct RootPaths {  // paths[x]: XOR of the letter bits from the root down to x
    Tree& tree;
    std::vector<int> start, fenwick;  // the masks for the initial letters, and a Fenwick tree over the Euler tour with the changes since the start

    RootPaths(Tree& tree, std::vector<int>& bit) : tree(tree), start(bit), fenwick(bit.size() + 1) {
        for (int x : tree.order)  // a parent comes before its children in DFS order
            if (x != tree.parent[x]) start[x] ^= start[tree.parent[x]];
    }

    void flip(int x, int d) {  // XOR d into the root path of every node in x's subtree
        for (int i : {tree.tin[x] + 1, tree.tout[x] + 1})  // d starts at x's subtree and cancels out after it
            for (; i < static_cast<int>(fenwick.size()); i += i & -i) fenwick[i] ^= d;
    }

    int operator[](int x) {
        int mask = start[x];
        for (int i = tree.tin[x] + 1; i > 0; i -= i & -i) mask ^= fenwick[i];
        return mask;
    }
};

int number(const std::string& q, int i) {  // the number that starts at q[i]
    int x = 0;
    for (; i < static_cast<int>(q.size()) && std::isdigit(static_cast<unsigned char>(q[i])); i++)
        x = x * 10 + (q[i] - '0');
    return x;
}

}  // namespace

std::vector<bool> palindromePath(int n, std::vector<std::vector<int>>& edges, const std::string& s,
                                 std::vector<std::string>& queries) {
    Tree tree(n, edges);
    std::vector<int> bit(n);  // bit[x]: the bit of x's letter
    for (int x = 0; x < n; x++) bit[x] = 1 << (s[x] - 'a');
    RootPaths paths(tree, bit);

    std::vector<bool> ans;
    for (auto& q : queries) {
        if (q[0] == 'u') {  // "update x c"
            int x = number(q, 7), newBit = 1 << (q.back() - 'a');
            paths.flip(x, bit[x] ^ newBit);  // the new letter changes the root path of every node in x's subtree
            bit[x] = newBit;
        } else {  // "query u v"
            int u = number(q, 6), v = number(q, static_cast<int>(q.rfind(' ')) + 1);
            int mask = paths[u] ^ paths[v] ^ bit[tree.lca(u, v)];  // the LCA cancels out in paths[u] ^ paths[v], so add it back
            ans.push_back((mask & (mask - 1)) == 0);  // at most one letter is odd; std::popcount is C++20
        }
    }
    return ans;
}
