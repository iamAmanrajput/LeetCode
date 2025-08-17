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
    int getLength(ListNode* head) {
        int count = 0;
        while (head) {
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }

        int length = getLength(head);
        int actualRotateK = (k % length);
        if (actualRotateK == 0) {
            return head;
        }
        int newLastNodePosition = length - actualRotateK - 1;

        ListNode* newLastNode = head;
        for (int i = 0; i < newLastNodePosition; i++) {
            newLastNode = newLastNode->next;
        }
        ListNode* newHead = newLastNode->next;
        newLastNode->next = NULL;
        ListNode* it = newHead;
        while (it->next) {
            it = it->next;
        }
        it->next = head;
        return newHead;
    }
};