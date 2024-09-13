class Solution {
  public:
    int longestCommonSubstr(string s, string t) {
        // your code here
          int n=s.size(),m=t.size();
        vector<int>prev(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>temp(m,0);
            for(int j=0;j<m;j++){
    if(s[i]==t[j] ) {
        if(i>0 && j>0){
        temp[j]=1+prev[j-1];
        }else{
            temp[j]=1;
        }

    }else{
           temp[j]=0;
            }
                 ans=max(ans,temp[j]);
        }
        prev=temp;
   
        }
      
        return ans;
    
    }
};
