class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }
        
        sort(count.begin(), count.end());
        
        int maxFreq = count[25];
        int maxFreqCnt = 1;
        
        for (int i = 24; i >= 0; i--) {
            if (count[i] == maxFreq) {
                maxFreqCnt++;
            } else {
                break;
            }
        }
        
        int ans = (maxFreq - 1) * (n + 1);
        ans += maxFreqCnt;
        
        return max((int)tasks.size(), ans);
    }
};
