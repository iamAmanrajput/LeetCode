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
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder, int size,
                    int& preIndex, int inorderStart, int inorderEnd,
                    map<int, int>& nodeToIndex) {

        // base case
        if (preIndex >= size || inorderStart > inorderEnd) {
            return NULL;
        }

        // STEP A:
        int element = preorder[preIndex++];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];

        // STEP B:
        root->left = solve(inorder, preorder, size, preIndex, inorderStart,
                           position - 1, nodeToIndex);

        // STEP C:
        root->right = solve(inorder, preorder, size, preIndex, position + 1,
                            inorderEnd, nodeToIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        map<int, int> nodeToIndex;

        for (int i = 0; i < n; i++) {
            nodeToIndex[inorder[i]] = i;
        }

        int preIndex = 0;
        return solve(inorder, preorder, n, preIndex, 0, n - 1, nodeToIndex);
    }
};