#pragma once

#include "trees/tree_node.hpp"

// Counts the nodes whose value equals the average of every value in their own
// subtree, with the average rounded down to the nearest integer.
int averageOfSubtree(TreeNode* root);
