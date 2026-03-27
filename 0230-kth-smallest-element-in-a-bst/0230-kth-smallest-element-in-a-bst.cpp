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
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        solve(root, k, ans);
        return ans;
    }

    void solve(TreeNode* root, int &k, int &ans) {
        if (!root) return;

        // Left
        solve(root->left, k, ans);

        // Process current node
        k--;
        if (k == 0) {
            ans = root->val;
            return;
        }

        // Right (only if answer not found yet)
        solve(root->right, k, ans);
    }
};