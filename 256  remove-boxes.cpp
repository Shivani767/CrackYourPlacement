class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 0)));

        // Initialize dp table
        for (int l = n - 1; l >= 0; l--) {
            for (int r = l; r < n; r++) {
                for (int k = 0; k <= l; k++) {
                    int& ret = dp[l][r][k]; // shortcut for readability

                    // Base case: no boxes to remove
                    if (l == r) {
                        ret = (k + 1) * (k + 1);
                    } else {
                        ret = (k + 1) * (k + 1) + (l + 1 <= r ? dp[l + 1][r][0] : 0);

                        // Try to merge non-contiguous segments
                        for (int j = l + 1; j <= r; j++) {
                            if (boxes[j] == boxes[l]) {
                                ret = max(ret, dp[l + 1][j - 1][0] + dp[j][r][k + 1]);
                            }
                        }
                    }
                }
            }
        }

        return dp[0][n - 1][0];
    }
};
