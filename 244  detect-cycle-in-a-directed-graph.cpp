class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>indegree(V);
	    for(int i=0;i<V;i++){
	        for(int &it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int>q;
	    int res=0;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        
	        res++;
	        
	        for(int &neigh:adj[node]){
	            indegree[neigh]--;
	            if(indegree[neigh]==0) q.push(neigh);
	        }
	    }
	    if(res==V) return false;
	    return true;
	   // return res;
    }
};
