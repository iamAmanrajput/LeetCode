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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2){
            return list2;
        }
        if(list2 == NULL && list1){
            return list1;
        }
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                if (ansHead == NULL) {
                    ansHead = list1;
                    ansTail = list1;
                    list1 = list1->next;
                    ansHead->next = NULL;
                } else {
                    ansTail->next = list1;
                    ansTail = ansTail->next;
                    list1 = list1->next;
                    ansTail->next = NULL;
                }
            } else {
                if (ansHead == NULL) {
                    ansHead = list2;
                    ansTail = list2;
                    list2 = list2->next;
                    ansHead->next = NULL;
                } else {
                    ansTail->next = list2;
                    ansTail = ansTail->next;
                    list2 = list2->next;
                    ansTail->next = NULL;
                }
            }
        }

        while (list1 != NULL) {
            ansTail->next = list1;
            ansTail = ansTail->next;
            list1 = list1->next;
            ansTail->next = NULL;
        }

        while (list2 != NULL) {
            ansTail->next = list2;
            ansTail = ansTail->next;
            list2 = list2->next;
            ansTail->next = NULL;
        }

        return ansHead;
    }
};