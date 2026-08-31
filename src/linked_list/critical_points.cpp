#include "linked_list/critical_points.hpp"

#include <algorithm>
#include <climits>

std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    // A critical point needs a neighbour on each side, so walk a window of
    // three nodes and note the position of every local peak or valley.
    int first = -1, last = -1, minDistance = INT_MAX, index = 1;
    for (ListNode* prev = head; prev != nullptr && prev->next != nullptr && prev->next->next != nullptr;
         prev = prev->next, index++) {
        ListNode* curr = prev->next;
        bool peak = curr->val > prev->val && curr->val > curr->next->val;
        bool valley = curr->val < prev->val && curr->val < curr->next->val;
        if (!peak && !valley) continue;

        // The closest pair is always two neighbouring critical points, and the
        // widest is always the outermost pair, so only the previous position
        // and the first one ever matter.
        if (first < 0) first = index;
        else minDistance = std::min(minDistance, index - last);
        last = index;
    }

    if (first == last) return {-1, -1};
    return {minDistance, last - first};
}
