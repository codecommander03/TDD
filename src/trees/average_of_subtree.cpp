#include "trees/average_of_subtree.hpp"

#include <functional>
#include <utility>

int averageOfSubtree(TreeNode* root) {
    int res = 0;

    // Each node needs its subtree's size and total, and both are just the two
    // children's answers plus the node itself, so one post-order walk settles
    // every node on the way back up.
    std::function<std::pair<int, int>(TreeNode*)> help = [&](TreeNode* x) -> std::pair<int, int> {
        if (x == nullptr) return {0, 0};

        std::pair<int, int> l = help(x->left), r = help(x->right);
        int cnt = l.first + r.first + 1, sum = l.second + r.second + x->val;
        if (sum / cnt == x->val) res++;
        return {cnt, sum};
    };

    help(root);
    return res;
}
