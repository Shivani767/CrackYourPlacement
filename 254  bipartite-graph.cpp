class Solution {
public:
	bool isBipartite(int n, vector<int>adj[]){
	    queue<pair<int,int>> q;
    	vector<int> v(n,-1);
	    for(int ii=0;ii<n;ii++){
	        if(v[ii]==-1){
        	    q.push({ii,0});
        	    v[0]=0;
        	    while(!q.empty()){
        	        int i=q.front().first;
        	        int c=q.front().second;
        	        q.pop();
        	        for(int j=0;j<adj[i].size();j++){
        	            if(v[adj[i][j]]==-1){
        	                v[adj[i][j]]=c^1;
        	                q.push({adj[i][j],c^1});
        	            }
        	            else{
        	                if(v[adj[i][j]]==c){
        	                    return false;
        	                }
        	            }
        	        }
        	    }
	        }
	    }
	    return true;
	}

};
