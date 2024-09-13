

class Solution
{
    public:
    //Function to find the largest number after k swaps.
    
    void solve(int idx, string &str, string &ans, int k){
        if(k == 0 || idx >= str.size()){
            ans = max(str, ans);
            return;
        }
        char mx = str[idx];
        for(int i = idx; i<str.size(); i++){
            if(i == idx){
                solve(idx+1, str, ans, k);
            }
            if(str[i]> mx){
                swap(str[idx], str[i]);
                solve(idx+1, str, ans, k-1);
                swap(str[idx], str[i]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans;
       int idx = 0;
       solve(idx, str, ans,k);
       return ans;
    }
};
