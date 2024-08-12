class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        for (char c : num) {
            while (k > 0 && !res.empty() && res.back() > c) {
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }
        while (k-- > 0) {
            res.pop_back();
        }
        int start = 0;
        while (start < res.size() && res[start] == '0') {
            start++;
        }
        return start == res.size() ? "0" : res.substr(start);
    }
};
