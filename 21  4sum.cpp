#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int left = j + 1;
                int right = nums.size() - 1;
                
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum < target) {
                        left++;
                    } else if (sum > target) {
                        right--;
                    } else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        
                        left++;
                        right--;
                    }
                }
                
                while (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
                    j++;
                }
            }
            
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        
        return result;
    }
};
