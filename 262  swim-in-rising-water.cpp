class Solution {
public:
    bool dfs(vector<vector<int>> &grid , int x , int y , vector<vector<int>>&vis , int t){
        int n = grid.size();
        vis[x][y] = 1;
        int dx[4] = {-1 , 0 , 1 , 0};
        int dy[4] = {0 , 1 , 0 , -1};
        if(x  == n-1 and y == n-1)return true;
        for(int i= 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=0  and ny >=0 and nx < n and ny < n ){
                // Important Condition grid[nx][ny] <= t
                if( grid[nx][ny] <= t and vis[nx][ny] == 0){
                     if(dfs(grid, nx , ny , vis , t) == true)return true;
                }
            }
        }
        return false;
    }
    bool check(vector<vector<int>>& grid , int t){
        bool ans = false;
        int n = grid.size();
        vector<vector<int>> vis(n+1 , vector<int>(n+1  , 0));
        if(grid[0][0] <= t){
           ans =  dfs(grid ,0 , 0 , vis , t );
        }
        return ans;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0 , high = n*n;
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(check(grid , mid )){
                ans = mid;
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
