class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeaves(root, false);
    }

    int sumOfLeftLeaves(TreeNode* node, bool isLeft) {
        if (node == nullptr) {
            return 0;
        }

        if (node->left == nullptr && node->right == nullptr && isLeft) {
            return node->val;
        }

        return sumOfLeftLeaves(node->left, true) + sumOfLeftLeaves(node->right, false);
    }
};
