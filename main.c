#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    // Base case: if the current segment has less than k nodes, return head
    struct ListNode* current = head;
    int count = 0;
    while (count < k && current) {
        current = current->next;
        count++;
    }
    if (count < k) {
        return head;
    }

    // Reverse the current segment
    struct ListNode* prev = NULL;
    struct ListNode* next_node = NULL;
    current = head;
    for (int i = 0; i < k; i++) {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }

    // Recursively reverse the next segment
    head->next = reverseKGroup(current, k);

    return prev;
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf(",");
        }
        current = current->next;
    }
}

int main() {
    struct ListNode* l5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l5->val = 5;
    l5->next = NULL;
    struct ListNode* l4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l4->val = 4;
    l4->next = l5;
    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3->val = 3;
    l3->next = l4;
    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->val = 2;
    l2->next = l3;
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 1;
    l1->next = l2;

    int k = 3;

    struct ListNode* newHead = reverseKGroup(l1, k);

    printf("[");
    printList(newHead);
    printf("]");

    return 0;
}