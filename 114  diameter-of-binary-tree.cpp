class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }

    int depth(TreeNode* node, int& diameter) {
        if (node == nullptr) return 0;
        int left = depth(node->left, diameter);
        int right = depth(node->right, diameter);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }
};
