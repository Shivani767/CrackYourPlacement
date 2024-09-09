class Solution {
  public:
  void solve(int i,int j,vector<string>&ans,vector<vector<int>>&mat,string move,vector<vector<int>>&vis,int n)
  {
      if(i==n-1 && j==n-1)
      {
          ans.push_back(move);
          return;
      }
      
      //down
      if(i+1<n && vis[i+1][j]!=1 && mat[i+1][j]==1)
      {
          vis[i][j]=1;
          solve(i+1,j,ans,mat,move+'D',vis,n);
          vis[i][j]=0;
         
      }
      //left
      if(j-1>=0 && vis[i][j-1]!=1 && mat[i][j-1]==1)
      {
          vis[i][j]=1;
          solve(i,j-1,ans,mat,move+'L',vis,n);
          vis[i][j]=0;
      }
      //right
      if(j+1<n && vis[i][j+1]!=1 && mat[i][j+1]==1)
      {
          vis[i][j]=1;
          solve(i,j+1,ans,mat,move+'R',vis,n);
          vis[i][j]=0;
      }
      //up
      if(i-1>=0 && vis[i-1][j]!=1 && mat[i-1][j]==1)
      {
          vis[i][j]=1;
          solve(i-1,j,ans,mat,move+'U',vis,n);
          vis[i][j]=0;
      }
    
  }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string>ans;
        int n=mat.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        string move="";
        if(mat[0][0]==1)solve(0,0,ans,mat,move,vis,n);
        
        return ans;
        
    }
};
