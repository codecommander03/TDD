#include "trees/tree_node.hpp"

#include <queue>

TreeNode* buildTree(const std::vector<std::optional<int>>& values) {
    if (values.empty() || !values[0].has_value()) return nullptr;

    TreeNode* root = new TreeNode(*values[0]);
    std::queue<TreeNode*> pending;
    pending.push(root);

    // The listing names the two children of every node already placed, in the
    // order those nodes were reached, so one queue is enough to attach them.
    int i = 1;
    int n = static_cast<int>(values.size());
    while (!pending.empty() && i < n) {
        TreeNode* node = pending.front();
        pending.pop();

        if (i < n && values[i].has_value()) {
            node->left = new TreeNode(*values[i]);
            pending.push(node->left);
        }
        i++;

        if (i < n && values[i].has_value()) {
            node->right = new TreeNode(*values[i]);
            pending.push(node->right);
        }
        i++;
    }

    return root;
}

void freeTree(TreeNode* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
