class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
       vector<long long int> p(nums.size());
        long long int pr = 1;    // store value of product
        int check = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                check++;
                continue;
            }
            else pr *= nums[i];
        }
        
        for(int i=0; i<p.size(); i++){
            if(check == 0 ) p[i] = pr/nums[i];
            else if(check == 1 && nums[i] == 0) p[i] = pr;
            else p[i] = 0;
        }
        
        return p;
    }
};
