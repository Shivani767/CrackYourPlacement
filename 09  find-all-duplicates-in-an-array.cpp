class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int num = abs(nums[i]);
            if (nums[num - 1] < 0) {
                res.push_back(num);
            } else {
                nums[num - 1] *= -1;
            }
        }
        return res;
    }
};
