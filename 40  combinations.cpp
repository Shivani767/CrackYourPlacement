class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        backtrack(result, {}, 1, n, k);
        return result;
    }
    
private:
    void backtrack(vector<vector<int>>& result, vector<int> current, int start, int n, int k) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i <= n; i++) {
            current.push_back(i);
            backtrack(result, current, i + 1, n, k);
            current.pop_back();
        }
    }
};
