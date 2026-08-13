#include "segment_tree/longest_repeating.hpp"
#include <algorithm>

namespace {

struct Node {
    int max_len, pref_len, suff_len;
    char left_char, right_char;
    int size;
};

std::vector<Node> tree;

Node combine(const Node& l, const Node& r) {
    Node res;
    res.size = l.size + r.size;
    res.left_char = l.left_char;
    res.right_char = r.right_char;

    res.max_len = std::max(l.max_len, r.max_len);
    res.pref_len = l.pref_len;
    res.suff_len = r.suff_len;

    if (l.right_char == r.left_char) {
        res.max_len = std::max(res.max_len, l.suff_len + r.pref_len);

        if (l.pref_len == l.size) res.pref_len = l.size + r.pref_len;
        if (r.suff_len == r.size) res.suff_len = r.size + l.suff_len;
    }
    return res;
}

void build(int node, int start, int end, const std::string& s) {
    if (start == end) {
        tree[node] = {1, 1, 1, s[start], s[start], 1};
        return;
    }

    int mid = start + (end - start) / 2;
    build(2 * node, start, mid, s);
    build(2 * node + 1, mid + 1, end, s);

    tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

void update(int node, int start, int end, int idx, char c) {
    if (start == end) {
        tree[node] = {1, 1, 1, c, c, 1};
        return;
    }

    int mid = start + (end - start) / 2;
    if (idx <= mid) update(2 * node, start, mid, idx, c);
    else update(2 * node + 1, mid + 1, end, idx, c);

    tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}


std::vector<int> longestRepeating(std::string s, std::string queryCharacters, std::vector<int>& queryIndices) {
    int n = s.size(), k = queryCharacters.size();
    tree.assign(4 * n, Node{});
    build(1, 0, n - 1, s);

    std::vector<int> res(k);
    for (int i = 0; i < k; ++i) {
        update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
        res[i] = tree[1].max_len;
    }
    return res;
}