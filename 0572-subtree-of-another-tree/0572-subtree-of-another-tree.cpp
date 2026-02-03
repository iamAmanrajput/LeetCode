class Solution {
public:
    // Helper function: check karta hai ki
    // dono trees exactly same hain ya nahi
    bool isSameTree(TreeNode* root, TreeNode* subRoot) {

        // Agar dono NULL hain → same
        if (root == NULL && subRoot == NULL) {
            return true;
        }

        // Agar ek NULL hai aur doosra nahi → not same
        if (root == NULL || subRoot == NULL) {
            return false;
        }

        // Agar values match nahi karti → not same
        if (root->val != subRoot->val) {
            return false;
        }

        // Left aur right subtree recursively check karo
        return isSameTree(root->left, subRoot->left) &&
               isSameTree(root->right, subRoot->right);
    }

    // Main function: check karta hai
    // subRoot, root ka subtree hai ya nahi
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // Agar root NULL hai
        // to subtree sirf tab possible hai jab subRoot bhi NULL ho
        if (root == NULL) {
            return subRoot == NULL;
        }

        // Agar current node se tree same mil gaya
        if (isSameTree(root, subRoot)) {
            return true;
        }

        // Nahi mila to left ya right subtree me search karo
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
