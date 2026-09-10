#pragma once

#include <optional>
#include <vector>

// Shared binary tree node for the trees problems.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Builds a tree from LeetCode's level-order listing, where std::nullopt marks a
// missing child and children of missing nodes are left out entirely; returns
// nullptr when values is empty. The caller owns the nodes and frees them with
// freeTree.
TreeNode* buildTree(const std::vector<std::optional<int>>& values);

// Releases every node reachable from root.
void freeTree(TreeNode* root);
