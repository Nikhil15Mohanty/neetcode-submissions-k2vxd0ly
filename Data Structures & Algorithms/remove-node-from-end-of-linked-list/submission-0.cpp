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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;
        while(temp !=NULL) {
            length++;
            temp = temp -> next;
        }
        if (length == n) {
            ListNode* removeHead = head->next;
            delete(head);
            return removeHead;
        }
        int travel = length - n;

        ListNode* p = head;
        ListNode* q = nullptr;

        while (travel--) {
            q = p;
            p = p -> next;
        }
        q->next = p->next;
        delete(p);
        return head;
    }
};
