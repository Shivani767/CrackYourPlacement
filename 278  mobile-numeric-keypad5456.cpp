class Solution {
    private:
    long long solve(int arr[4][3], int n, int i, int j, vector<vector<vector<long long>>> &dp){
        if(n==0) return 1;
        
        if(dp[n][i][j]!=-1) return dp[n][i][j];
        
        long long a=0, b=0, c=0, d=0;
        
        if(i-1>=0 && arr[i-1][j]!=-1){
            a=solve(arr,n-1,i-1,j,dp);
        }
        if(j+1<3 && arr[i][j+1]!=-1){
            b=solve(arr,n-1,i,j+1,dp);
        }
        if(i+1<4 && arr[i+1][j]!=-1){
            c=solve(arr,n-1,i+1,j,dp);
        }
        if(j-1>=0 && arr[i][j-1]!=-1){
            d=solve(arr,n-1,i,j-1,dp);
        }
        
        long long e=solve(arr,n-1,i,j,dp);
        
        dp[n][i][j]=a+b+c+d+e;
        return dp[n][i][j];
    }
  public:
    long long getCount(int n) {
        // Your code goes here
        int arr[4][3]={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        
        vector<vector<vector<long long>>> dp(n+1,
            vector<vector<long long>> (4,vector<long long>(3,-1)));
        
        long long ans=0;
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                if(arr[i][j]!=-1){
                    ans=ans+solve(arr,n-1,i,j,dp);
                }
            }
        }
        
        return ans;
    }
};
