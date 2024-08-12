class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNums(n + 2, 1);
        for (int i = 0; i < n; i++) {
            newNums[i + 1] = nums[i];
        }
        
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int length = 1; length <= n; length++) {
            for (int left = 1; left <= n - length + 1; left++) {
                int right = left + length - 1;
                for (int i = left; i <= right; i++) {
                    dp[left][right] = max(dp[left][right], dp[left][i - 1] + dp[i + 1][right] + newNums[left - 1] * newNums[i] * newNums[right + 1]);
                }
            }
        }
        
        return dp[1][n];
    }
};
