class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

private:
    bool isValidBST(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true;
        if (node->val <= minVal || node->val >= maxVal) return false;
        return isValidBST(node->left, minVal, node->val) && isValidBST(node->right, node->val, maxVal);
    }
};
