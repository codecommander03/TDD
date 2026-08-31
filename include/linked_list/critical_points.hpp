#pragma once

#include <vector>

#include "linked_list/list_node.hpp"

// A critical point is a node with a neighbour on each side whose value is
// either larger or smaller than both of them; returns the smallest and largest
// distance between two critical points, or {-1, -1} if there are fewer than two.
std::vector<int> nodesBetweenCriticalPoints(ListNode* head);
