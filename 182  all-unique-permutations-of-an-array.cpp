class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<vector<int>>ans;
         sort(arr.begin(),arr.end());
        vector<int>temp = arr;
        ans.push_back(temp);
        next_permutation(temp.begin(),temp.end());
        while(temp!=arr){
            ans.push_back(temp);
            next_permutation(temp.begin(),temp.end());
        }
        return ans;
    }
};
