class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = processString(s);
        string t1 = processString(t);
        return s1 == t1;
    }
    
    string processString(string s) {
        string res;
        for (char c : s) {
            if (c == '#') {
                if (!res.empty()) {
                    res.pop_back();
                }
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};
