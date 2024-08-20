/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        if (preorder.size() == 1) return root;
        
        int idx = 0;
        for (int i = 0; i < postorder.size(); i++) {
            if (postorder[i] == preorder[1]) {
                idx = i;
                break;
            }
        }
        
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + idx + 2);
        vector<int> rightPreorder(preorder.begin() + idx + 2, preorder.end());
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + idx + 1);
        vector<int> rightPostorder(postorder.begin() + idx + 1, postorder.end() - 1);
        
        root->left = constructFromPrePost(leftPreorder, leftPostorder);
        root->right = constructFromPrePost(rightPreorder, rightPostorder);
        
        return root;
    }
};
