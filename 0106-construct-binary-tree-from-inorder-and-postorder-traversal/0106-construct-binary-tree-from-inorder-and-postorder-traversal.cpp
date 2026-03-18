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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int size,
                    int& postIndex, int inorderStart, int inorderEnd,
                    map<int, int>& nodeToIndex) {

        // base case
        if (postIndex < 0 || inorderStart > inorderEnd) {
            return NULL;
        }

        // STEP A:
        int element = postorder[postIndex--];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];

        // STEP C:
        root->right = solve(inorder, postorder, size, postIndex, position + 1,
                            inorderEnd, nodeToIndex);

        // STEP B:
        root->left = solve(inorder, postorder, size, postIndex, inorderStart,
                           position - 1, nodeToIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        map<int, int> nodeToIndex;
        for (int i = 0; i < n; i++) {
            nodeToIndex[inorder[i]] = i;
        }

        int postIndex = n - 1;
        return solve(inorder, postorder, n, postIndex, 0, n - 1, nodeToIndex);
    }
};