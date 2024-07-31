class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Phase 1: Detecting the cycle using Floyd's Tortoise and Hare algorithm
        int tortoise = nums[0];
        int hare = nums[0];
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Phase 2: Finding the start of the cycle
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};
