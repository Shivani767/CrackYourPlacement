#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(result, current, candidates, target, 0);
        return result;
    }

private:
    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& current, std::vector<int>& candidates, int target, int start) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size() && candidates[i] <= target; ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            current.push_back(candidates[i]);
            backtrack(result, current, candidates, target - candidates[i], i + 1);
            current.pop_back();
        }
    }
};
