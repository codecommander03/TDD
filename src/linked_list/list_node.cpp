#include "linked_list/list_node.hpp"

ListNode* buildList(const std::vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int value : values) {
        ListNode* node = new ListNode(value);
        if (tail == nullptr) head = node;
        else tail->next = node;
        tail = node;
    }
    return head;
}

void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}
