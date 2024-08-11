#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        vector<int> count(n + 1, 0);
        for (int num : nums) {
            count[num]++;
        }

        vector<int> dp(n + 1, 0);
        dp[1] = count[1];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + i * count[i]);
        }

        return dp[n];
    }
};
