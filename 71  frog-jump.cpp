class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, unordered_set<int>> dp;
        dp[0].insert(0);
        for (int i = 0; i < n; i++) {
            for (int k : dp[stones[i]]) {
                for (int j = k - 1; j <= k + 1; j++) {
                    if (j > 0) {
                        dp[stones[i] + j].insert(j);
                    }
                }
            }
        }
        return !dp[stones.back()].empty();
    }
};
