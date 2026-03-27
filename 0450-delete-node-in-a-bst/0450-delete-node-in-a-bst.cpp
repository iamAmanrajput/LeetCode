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
    int maxVal(TreeNode* root) {
        TreeNode* temp = root;

        // If tree is empty
        if (temp == NULL) {
            return -1;
        }

        // Move to the rightmost node
        while (temp->right != NULL) {
            temp = temp->right;
        }

        // Return maximum value
        return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int target) {
        // base case
        if (root == NULL) {
            return NULL;
        }

        if (root->val == target) {
            // 4 Cases
            if (root->left == NULL && root->right == NULL) {
                // Leaf Node
                delete root;
                return NULL;
            } else if (root->left == NULL && root->right != NULL) {
                TreeNode* child = root->right;
                delete root;
                return child;
            } else if (root->left != NULL && root->right == NULL) {
                TreeNode* child = root->left;
                delete root;
                return child;
            } else {
                // Exists Both Child
                // Find Inorder predecessor in left subtree
                int inorderPred = maxVal(root->left);
                // replace root->data with inorder predecessor
                root->val = inorderPred;
                // delete inorder predecessor from left subtree
                root->left = deleteNode(root->left, inorderPred);
                return root;
            }
        } else if (target > root->val) {
            // Go Right
            root->right = deleteNode(root->right, target);
        } else if (target < root->val) {
            // Go Left
            root->left = deleteNode(root->left, target);
        }
        return root;
    }
};