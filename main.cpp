#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;

        ListNode* tail = head;

        for (int i = 0; i < k; ++i) {
            if (tail == nullptr)  // Less than k nodes, do nothing
                return head;
            tail = tail->next;
        }

        ListNode* newHead = reverse(head, tail);
        head->next = reverseKGroup(tail, k);
        return newHead;
    }

private:
    // Reverses [head, tail)
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != tail) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

std::vector<int> getListValues(ListNode* head) {
    std::vector<int> values;
    while (head != nullptr) {
        values.push_back(head->val);
        head = head->next;
    }
    return values;
}

int main() {
    ListNode* l5 = new ListNode(5);
    ListNode* l4 = new ListNode(4, l5);
    ListNode* l3 = new ListNode(3, l4);
    ListNode* l2 = new ListNode(2, l3);
    ListNode* l1 = new ListNode(1, l2);

    Solution solution;
    int k = 3;

    ListNode* newHead = solution.reverseKGroup(l1, k);

    std::cout << "[";
    std::vector<int> modifiedList = getListValues(newHead);
    for (int i = 0; i < modifiedList.size(); ++i) {
        if (i < modifiedList.size() - 1) {
            std::cout << modifiedList[i] << ", ";
        } else {
            std::cout << modifiedList[i];
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}