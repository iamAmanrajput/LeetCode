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
    // DFS helper function
    void sumHelper(TreeNode* root, int& targetSum, vector<vector<int>>& ans,
                   vector<int>& currAns, int currSum) {

        // Base case: agar node NULL hai to return
        if (root == NULL)
            return;

        // Current node ko path me add karo
        currAns.push_back(root->val);

        // Running sum update karo
        currSum += root->val;

        // Check: agar leaf node hai
        if (root->left == NULL && root->right == NULL) {

            // Agar sum target ke equal hai to path store karo
            if (currSum == targetSum) {
                ans.push_back(currAns);
            }
        }

        // Left subtree explore karo
        sumHelper(root->left, targetSum, ans, currAns, currSum);

        // Right subtree explore karo
        sumHelper(root->right, targetSum, ans, currAns, currSum);

        // Backtracking:
        // current node ko path se hatao taaki dusre paths explore ho sake
        currAns.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans; // final answer store karega
        vector<int> currAns;     // current path store karega

        // DFS start karo with initial sum = 0
        sumHelper(root, targetSum, ans, currAns, 0);

        return ans;
    }
};