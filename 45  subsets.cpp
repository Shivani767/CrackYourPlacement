class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(result, current, nums, 0);
        return result;
    }

private:
    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& current, std::vector<int>& nums, int start) {
        result.push_back(current);
        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            backtrack(result, current, nums, i + 1);
            current.pop_back();
        }
    }
};
