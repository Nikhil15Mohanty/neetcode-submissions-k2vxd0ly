class Solution {
public:

    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<
            ListNode*,
            vector<ListNode*>,
            Compare
        > minHeap;

        // Put the head of every list into the heap
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }

        // Dummy node
        ListNode* temp = new ListNode(-1);
        ListNode* tail = temp;

        while (!minHeap.empty()) {

            // Get smallest node
            ListNode* smallestNode = minHeap.top();
            minHeap.pop();

            // Add it to result
            tail->next = smallestNode;
            tail = tail->next;

            // Add next node from the same list
            if (smallestNode->next != nullptr) {
                minHeap.push(smallestNode->next);
            }
        }

        return temp->next;
    }
};