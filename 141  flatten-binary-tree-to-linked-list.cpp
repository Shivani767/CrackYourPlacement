class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        root->left = nullptr;
        
        if (left) {
            root->right = left;
            TreeNode* curr = left;
            while (curr->right) {
                curr = curr->right;
            }
            curr->right = right;
        } else {
            root->right = right;
        }
        
        flatten(root->right);
    }
};
