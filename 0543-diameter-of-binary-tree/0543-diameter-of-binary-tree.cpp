/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Height function jo diameter ko reference se update karta hai
    int height(TreeNode* root, int &diameter) {
        // Base case
        if (root == NULL) {
            return 0;
        }

        // Left aur right subtree ki height
        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);

        // Current node par diameter update
        diameter = max(diameter, leftHeight + rightHeight);

        // Height return
        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;   // Local variable (LeetCode preferred)
        height(root, diameter);
        return diameter;
    }
};
