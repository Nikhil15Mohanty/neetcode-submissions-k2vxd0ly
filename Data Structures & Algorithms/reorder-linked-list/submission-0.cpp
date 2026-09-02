/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseLL(ListNode* node) {
        if (node == NULL || node->next == NULL) return node;
        ListNode* last = reverseLL(node->next);
        node->next->next=node;
        node->next = NULL;
        return last;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* revHalf = reverseLL(slow);
        ListNode* current = head;
        while(revHalf->next) {
            ListNode* tempfront = current->next;
            current->next = revHalf;
            ListNode* tempback = revHalf->next;
            revHalf->next=tempfront;
            revHalf = tempback;
            current = tempfront;
        }
    }
};
