class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;
        inorder(root, first, second, prev);
        swap(first->val, second->val);
    }

private:
    void inorder(TreeNode* node, TreeNode*& first, TreeNode*& second, TreeNode*& prev) {
        if (!node) return;
        inorder(node->left, first, second, prev);
        if (prev && prev->val > node->val) {
            if (!first) {
                first = prev;
                second = node;
            } else {
                second = node;
            }
        }
        prev = node;
        inorder(node->right, first, second, prev);
    }
};
