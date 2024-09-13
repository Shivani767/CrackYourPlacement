//User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> currentList, vector<vector<bool>> &dp) {
        if (start == s.length()) {
            result.push_back(currentList);
            return;
        }
        
        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList, dp);
                currentList.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string s) {
        int len = s.length();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        vector<vector<string>> result;
        dfs(result, s, 0, vector<string>(), dp);
        return result;
    }


};
