class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }

private:
    int maxSum;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left = max(dfs(node->left), 0);
        int right = max(dfs(node->right), 0);

        maxSum = max(maxSum, node->val + left + right);

        return node->val + max(left, right);
    }
};
