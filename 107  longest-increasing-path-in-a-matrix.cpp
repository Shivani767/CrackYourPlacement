class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j] != 0) return dp[i][j];
        int val = matrix[i][j];
        int res = 1;
        if (i > 0 && matrix[i-1][j] > val) res = max(res, 1 + dfs(matrix, dp, i-1, j));
        if (i < matrix.size()-1 && matrix[i+1][j] > val) res = max(res, 1 + dfs(matrix, dp, i+1, j));
        if (j > 0 && matrix[i][j-1] > val) res = max(res, 1 + dfs(matrix, dp, i, j-1));
        if (j < matrix[0].size()-1 && matrix[i][j+1] > val) res = max(res, 1 + dfs(matrix, dp, i, j+1));
        dp[i][j] = res;
        return res;
    }
};
