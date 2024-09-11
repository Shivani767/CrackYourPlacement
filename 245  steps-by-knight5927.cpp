class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int n = N;
	    int x = KnightPos[0]-1;
	    int y = KnightPos[1]-1;
	    int x1 = TargetPos[0]-1;
	    int y1 = TargetPos[1]-1;
	    
	    
	    queue<pair<int,int>>q;
	    int ans = 0;
	    if(x==x1 && y==y1)return 0;
	    q.push({x,y});
	    vector<vector<int>>vis(n,vector<int>(n,0));
	   // vis[x][y] = 1;
	    
	    while(!q.empty()){
	        int size = q.size();
	        
	        for(int i=0;i<size;i++){
	            auto it = q.front();
	            q.pop();
	            
	            int x = it.first;
	            int y = it.second;
	            vis[x][y] = 1;
	            if(x==x1 && y==y1)return ans;
	            
	            int dx[8] = {2,2,-2,-2,1,-1,1,-1};
	            int dy[8] = {1,-1,1,-1,2,2,-2,-2};
	            
	            
	            for(int j=0;j<8;j++){
	                int newx = x + dx[j];
	                int newy = y + dy[j];
	                
	                if(newx>=0 && newy>=0 && newx<n && newy<n && vis[newx][newy]!=1){
	                    q.push({newx,newy});
	                    vis[newx][newy] = 1;
	                }
	            }
	        }
	        ans++;
	    }
	    return -1;
	    
	}
};
