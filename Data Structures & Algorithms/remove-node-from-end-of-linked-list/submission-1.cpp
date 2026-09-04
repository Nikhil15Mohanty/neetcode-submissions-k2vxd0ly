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
        ListNode* temp = head;
        for(int i = 1; i<=n;i++) {
            temp = temp -> next;
        }

        if (temp == NULL){
            ListNode* deleteNode = head->next;
            delete(head);
            return deleteNode;
        }


        ListNode* q = head;
        while(temp!=NULL && temp->next!=NULL) {
            q=q->next;
            temp=temp->next;
        }

        ListNode* toDelete = q->next;
        q->next = q->next->next;
        delete(toDelete);
        return head;


    }
};
