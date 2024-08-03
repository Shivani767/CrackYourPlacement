class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> sumCount;
        sumCount[0] = 1; // Initialize sumCount with 0 sum having 1 count
        
        for (int num : nums) {
            sum += num;
            if (sumCount.find(sum - k) != sumCount.end()) {
                count += sumCount[sum - k];
            }
            sumCount[sum]++;
        }
        
        return count;
    }
};
