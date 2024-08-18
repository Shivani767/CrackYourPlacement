/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        dfs(root, "", paths);
        return paths;
    }
    
    void dfs(TreeNode* node, string path, vector<string>& paths) {
        if (node == nullptr) return;
        
        path += to_string(node->val);
        
        if (node->left == nullptr && node->right == nullptr) {
            paths.push_back(path);
            return;
        }
        
        path += "->";
        
        dfs(node->left, path, paths);
        dfs(node->right, path, paths);
    }
};
