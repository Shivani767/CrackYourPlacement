class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        int m = s.size(), n = t.size();
        vector<int> map(128, 0);
        for (char c : t) ++map[c];
        int required = n, formed = 0;
        int windowCounts[128] = {0};
        int ans = INT_MAX, ansL = 0, ansR = 0;
        int l = 0, r = 0;
        while (r < m) {
            char c = s[r];
            windowCounts[c]++;
            if (map[c] > 0 && windowCounts[c] <= map[c]) formed++;
            while (l <= r && formed == required) {
                c = s[l];
                if (r - l + 1 < ans) {
                    ans = r - l + 1;
                    ansL = l;
                    ansR = r;
                }
                windowCounts[c]--;
                if (map[c] > 0 && windowCounts[c] < map[c]) formed--;
                l++;
            }
            r++;
        }
        return ans == INT_MAX ? "" : s.substr(ansL, ansR - ansL + 1);
    }
};
