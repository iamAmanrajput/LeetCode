/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Case 1: Both nodes are NULL
        if (p == NULL && q == NULL) {
            return true;
        }

        // Case 2: One is NULL, the other is not
        if (p == NULL && q != NULL) {
            return false;
        }

        if (p != NULL && q == NULL) {
            return false;
        }

        // Case 3: Values are different
        if (p->val != q->val) {
            return false;
        }

        // Case 4: Check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};