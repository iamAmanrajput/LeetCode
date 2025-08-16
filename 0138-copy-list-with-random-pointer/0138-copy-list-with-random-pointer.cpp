/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* helper(Node* head, unordered_map<Node*, Node*>& mp) {
        if (head == 0)
            return 0;

        Node* newHead = new Node(head->val);
        mp[head] = newHead;
        newHead->next = helper(head->next, mp);
        if (head->random) {
            newHead->random = mp[head->random];
        }
        return newHead;
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp; // old node --> new node
        return helper(head, mp);
    }
};