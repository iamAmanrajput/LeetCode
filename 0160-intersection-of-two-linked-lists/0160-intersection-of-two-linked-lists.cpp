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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) {
            return NULL;
        }

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while (temp1 && temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        ListNode* getBigger = temp1 == NULL ? headB : headA;

        int biggerLength = 0;

        while (temp1) {
            temp1 = temp1->next;
            biggerLength++;
        }

        while (temp2) {
            temp2 = temp2->next;
            biggerLength++;
        }

        if (headA == getBigger) {
            while (biggerLength != 0) {
                headA = headA->next;
                biggerLength--;
            }
        } else {
            while (biggerLength != 0) {
                headB = headB->next;
                biggerLength--;
            }
        }

        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};