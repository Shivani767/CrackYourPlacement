class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int dp[46]; // dp[i] represents the number of ways to climb i steps
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
