class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1; // base case: sum 0 mod k is 1
        int sum = 0, res = 0;
        for (int num : nums) {
            sum += num;
            int mod = (sum % k + k) % k; // handle negative mods
            if (count.find(mod) != count.end()) {
                res += count[mod];
            }
            count[mod]++;
        }
        return res;
    }
};
