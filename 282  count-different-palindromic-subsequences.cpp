class Solution {
private:
    // Helper function to get the previous occurrence of each character
    vector<int> getPrev(string s, int n) {
        vector<int> prev(n);
        unordered_map<char, int> mp;

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (mp.find(c) == mp.end()) {
                prev[i] = -1; // No previous occurrence
            } else {
                prev[i] = mp[c]; // Previous occurrence index
            }
            mp[c] = i; // Update the latest occurrence
        }
        return prev;
    }

    // Helper function to get the next occurrence of each character
    vector<int> getNext(string s, int n) {
        vector<int> next(n);
        unordered_map<char, int> mp;

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            if (mp.find(c) == mp.end()) {
                next[i] = -1; // No next occurrence
            } else {
                next[i] = mp[c]; // Next occurrence index
            }
            mp[c] = i; // Update the latest occurrence
        }
        return next;
    }

public:
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        const int MOD = 1e9 + 7; // To handle large numbers

        // DP table to store the count of palindromic subsequences
        vector<vector<int>> dp(n, vector<int>(n));

        // Get previous and next occurrence indices
        vector<int> prev = getPrev(s, n);
        vector<int> next = getNext(s, n);

        // Fill the DP table using a gap strategy
        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                if (gap == 0) {
                    dp[i][j] = 1; // Single character
                } else if (gap == 1) {
                    dp[i][j] = 2; // Two characters
                } else {
                    if (s[i] != s[j]) {
                        dp[i][j] = (static_cast<long long>(dp[i + 1][j]) + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                    } else {
                        int nextInd = next[i];
                        int prevInd = prev[j];

                        if (nextInd > prevInd) {
                            dp[i][j] = (2LL * dp[i + 1][j - 1] + 2) % MOD;
                        } else if (nextInd == prevInd) {
                            dp[i][j] = (2LL * dp[i + 1][j - 1] + 1) % MOD;
                        } else {
                            dp[i][j] = (2LL * dp[i + 1][j - 1] - dp[nextInd + 1][prevInd - 1] + MOD) % MOD;
                        }
                    }
                }
            }
        }

        // The result is the number of distinct palindromic subsequences in the entire string
        return dp[0][n - 1];
    }
};
