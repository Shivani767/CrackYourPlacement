class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	     vector<vector<int>> adj(N);
        vector<int> indegree(N);
        vector<int> ans;
        
        for(auto it  : prerequisites ){
            adj[it.second].push_back(it.first);
            indegree[it.first]++;
        }
        
        queue<int> q;
        for(int i=0;i<N;i++){
            if(indegree[i]==0){q.push(i);}
        }
        
        while(!q.empty()){
            int t = q.front();
            ans.push_back(t);
            q.pop();
            
            for(auto it : adj[t] ){
               indegree[it]--;
               if(indegree[it]==0){q.push(it);}
            }
        }
        
        
        return (ans.size()==N) ;
	}
};
