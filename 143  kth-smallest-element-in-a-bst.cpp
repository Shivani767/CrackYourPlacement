class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = 0;
        inOrder(root, k, count, result);
        return result;
    }

private:
    void inOrder(TreeNode* node, int k, int& count, int& result) {
        if (!node) return;
        inOrder(node->left, k, count, result);
        count++;
        if (count == k) {
            result = node->val;
            return;
        }
        inOrder(node->right, k, count, result);
    }
};
