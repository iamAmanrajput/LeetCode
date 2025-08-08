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
    ListNode* getmiddle(ListNode*& head) {
        if (head == NULL) {
            return head;
        }
        if (head->next == NULL) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (slow != NULL && fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    };

    ListNode* middleNode(ListNode* head) { return getmiddle(head); }
};