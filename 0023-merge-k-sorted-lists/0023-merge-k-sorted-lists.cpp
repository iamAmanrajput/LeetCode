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

// Comparator for min heap
class compare{
public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;  // min heap
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        int k = lists.size();

        if(k == 0){
            return NULL;
        }

        // Step 1: push first node of each list
        for(int i = 0; i < k; i++){
            if(lists[i] != NULL){
                minHeap.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        // Step 2: process heap
        while(!minHeap.empty()){
            ListNode* top = minHeap.top();
            minHeap.pop();

            // push next node of same list
            if(top->next){
                minHeap.push(top->next);
            }

            // build answer list
            if(head == NULL){
                head = top;
                tail = top;
            } else {
                tail->next = top;
                tail = top;
            }
        }

        return head;
    }
};