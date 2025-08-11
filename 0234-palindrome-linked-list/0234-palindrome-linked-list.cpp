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
    ListNode* reverseNode(ListNode*& prev, ListNode*& curr) {
        if(curr == NULL){
            return prev;
        }
        ListNode* forward = curr->next;
        curr->next = prev;
        return reverseNode(curr,forward);
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return false;
        }
        if (head->next == NULL) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* temp1 = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        ListNode* temp2 = reverseNode(prev,curr);
        
        while(temp2 != NULL){
            if(temp1->val != temp2->val){
                return false;
            }
            temp2 = temp2->next;
            temp1 = temp1->next;
        }

        return true;
        
    }
};