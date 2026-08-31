#pragma once

#include <vector>

// Shared singly-linked list node for the linked_list problems.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Builds a list holding values in order and returns its head, or nullptr when
// values is empty; the caller owns the nodes and frees them with freeList.
ListNode* buildList(const std::vector<int>& values);

// Releases every node reachable from head.
void freeList(ListNode* head);
