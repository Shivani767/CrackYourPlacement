class NumArray {
private:
    vector<int> prefixSum;
    vector<int> nums;

public:
    NumArray(vector<int>& nums) : nums(nums) {
        prefixSum.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
    }

    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        for (int i = index; i < nums.size(); i++) {
            prefixSum[i + 1] += diff;
        }
    }

    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
};
