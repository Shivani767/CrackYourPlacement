class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        
    vector<int> dp(n + 1, -1);
    dp[0] = 0; // Base case: no cuts for length 0
    
    // Iterate over each length from 1 to n
    for (int i = 1; i <= n; ++i) {
        // If the segment can be cut by length x
        if (i >= x && dp[i - x] != -1) {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }
        // If the segment can be cut by length y
        if (i >= y && dp[i - y] != -1) {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        // If the segment can be cut by length z
        if (i >= z && dp[i - z] != -1) {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }
    
    // Return the result for length n
    return dp[n] == -1 ? 0 : dp[n];
}
    
};
