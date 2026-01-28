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
    void traversalHelper(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }

        traversalHelper(root->left, ans);  // Left
        traversalHelper(root->right, ans); // Right
        ans.push_back(root->val);          // Root
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        traversalHelper(root, ans);

        return ans;
    }
};