class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> current;
        backtrack(result, current, s, 0);
        return result;
    }

private:
    void backtrack(std::vector<std::vector<std::string>>& result, std::vector<std::string>& current, std::string s, int start) {
        if (start == s.size()) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            std::string substr = s.substr(start, i - start + 1);
            if (isPalindrome(substr)) {
                current.push_back(substr);
                backtrack(result, current, s, i + 1);
                current.pop_back();
            }
        }
    }

    bool isPalindrome(std::string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }
};
