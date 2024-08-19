class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> values;
        inOrder(root, values);
        int minDiff = INT_MAX;
        for (int i = 1; i < values.size(); i++) {
            minDiff = min(minDiff, values[i] - values[i - 1]);
        }
        return minDiff;
    }

private:
    void inOrder(TreeNode* node, vector<int>& values) {
        if (!node) return;
        inOrder(node->left, values);
        values.push_back(node->val);
        inOrder(node->right, values);
    }
};
