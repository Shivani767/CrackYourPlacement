class Solution {
public:
    int find(int i, int j, vector<int>& prefix, int pile, vector<vector<int>>& dp) {
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i; k < j; k += pile-1) {
            int sum = find(i, k, prefix, pile, dp) + find(k+1, j, prefix, pile,dp);
            ans = min(ans, sum);
        }
        if((j-i) % (pile-1) == 0) 
            ans += prefix[j+1] - prefix[i];
        return dp[i][j] = ans;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        if((n-1) % (k-1) != 0) return -1;
        vector<int> prefix;
        prefix.push_back(stones[0]);
        for(int i = 0; i < stones.size(); i++)
            prefix.push_back(prefix.back() + stones[i]);
        return find(0, n-1, prefix, k, dp);
    }
};
