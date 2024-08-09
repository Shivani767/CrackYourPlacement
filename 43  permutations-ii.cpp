class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::vector<bool> visited(nums.size(), false);
        backtrack(result, current, nums, visited);
        return result;
    }

private:
    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& current, std::vector<int>& nums, std::vector<bool>& visited) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) continue;
            visited[i] = true;
            current.push_back(nums[i]);
            backtrack(result, current, nums, visited);
            current.pop_back();
            visited[i] = false;
        }
    }
};
