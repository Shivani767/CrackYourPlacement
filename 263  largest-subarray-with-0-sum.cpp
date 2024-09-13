/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        
        int ans=0;
        unordered_map<int,int> mp;
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(sum==0) ans=i+1;
            
            int rem=sum;
            
            if(mp.find(rem)!=mp.end()){
                ans=max(ans,i-mp[rem]);
            }
            
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        return ans;
    }
};
