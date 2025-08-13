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
    ListNode* reverse(ListNode*& head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        while (curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) {
            if (n == 1) {
                delete head;
                return NULL;
            }
            return head;
        }

        head = reverse(head);

        int i = 1;
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            if (i == n) {
                if (prev == NULL) {
                    head = curr->next;
                    delete curr;
                } else {
                    prev->next = curr->next;
                    delete curr;
                }
                break;
            }
            prev = curr;
            curr = curr->next;
            i++;
        }

        head = reverse(head);
        return head;
    }
};