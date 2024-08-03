class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        
        int mid = left + (right - left) / 2;
        int leftCount = mergeSort(nums, left, mid);
        int rightCount = mergeSort(nums, mid + 1, right);
        
        return leftCount + rightCount + merge(nums, left, mid, right);
    }

    int merge(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > 2 * (long long)nums[j]) {
                j++;
            }
            count += j - mid - 1;
        }
        
        vector<int> temp(right - left + 1);
        int k = 0;
        int i = left;
        j = mid + 1;
        
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        
        while (j <= right) {
            temp[k++] = nums[j++];
        }
        
        for (i = left; i <= right; i++) {
            nums[i] = temp[i - left];
        }
        
        return count;
    }
};
