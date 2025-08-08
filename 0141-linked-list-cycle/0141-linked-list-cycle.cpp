/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
          unordered_set<ListNode*> visited;
        
        ListNode* curr = head;
        while (curr != NULL) {
            if (visited.find(curr) != visited.end()) {
                return true; // cycle hai
            }
            visited.insert(curr);
            curr = curr->next;
        }
        return false; // cycle nahi hai
    }
};