#include "segment_tree/find_x_value_of_array_ii.hpp"
#include <algorithm>
#include <array>

namespace {

// prod is the product of the segment modulo mod; freq[r] counts the prefixes of
// the segment whose product is r modulo mod. k <= 5 by the constraints.
struct Node {
    int prod;
    std::array<int, 5> freq;
    Node() : prod(1) { freq.fill(0); }
};

int mod;
std::vector<Node> tree;
std::vector<int> values;

// The left half's prefixes carry over unchanged; each prefix of the right half
// is preceded by the whole left half, so its product picks up L.prod.
Node merge(const Node& L, const Node& R) {
    Node res;
    res.prod = static_cast<int>((1LL * L.prod * R.prod) % mod);
    res.freq = L.freq;
    for (int r = 0; r < mod; ++r) {
        if (R.freq[r]) {
            int nr = static_cast<int>((1LL * L.prod * r) % mod);
            res.freq[nr] += R.freq[r];
        }
    }
    return res;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v].prod = values[tl] % mod;
        tree[v].freq[tree[v].prod] = 1;
        return;
    }

    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);

    tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
}

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        tree[v].prod = val % mod;
        tree[v].freq.fill(0);
        tree[v].freq[tree[v].prod] = 1;
        return;
    }

    int tm = (tl + tr) / 2;
    if (pos <= tm) update(v * 2, tl, tm, pos, val);
    else update(v * 2 + 1, tm + 1, tr, pos, val);

    tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
}

// A default Node (product 1, no prefixes) is the identity for merge, so an
// empty range can be returned as-is.
Node query(int v, int tl, int tr, int l, int r) {
    if (l > r) return Node();
    if (l == tl && r == tr) return tree[v];

    int tm = (tl + tr) / 2;
    return merge(query(v * 2, tl, tm, l, std::min(r, tm)),
                 query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
}

}  // namespace

std::vector<int> resultArray(std::vector<int>& nums, int k, std::vector<std::vector<int>>& queries) {
    mod = k;
    values = nums;

    int n = static_cast<int>(nums.size());
    tree.assign(4 * n, Node());
    build(1, 0, n - 1);

    std::vector<int> ans;
    for (auto& q : queries) {
        int idx = q[0], val = q[1], start = q[2], x = q[3];
        update(1, 0, n - 1, idx, val);
        Node res = query(1, 0, n - 1, start, n - 1);
        ans.push_back(res.freq[x]);
    }
    return ans;
}
