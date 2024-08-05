class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string dir;
        
        while (getline(ss, dir, '/')) {
            if (dir == "" || dir == ".") continue;
            else if (dir == "..") {
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(dir);
            }
        }
        
        string res = "/";
        for (string s : stack) {
            res += s + "/";
        }
        
        return res == "/" ? res : res.substr(0, res.size() - 1);
    }
};
