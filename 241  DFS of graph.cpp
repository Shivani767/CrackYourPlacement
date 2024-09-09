class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        stack<int> s;
        vector<int> ans;
        int vis[V]={0};
        
        s.push(0);
        
        while(!s.empty()){
            int node = s.top();
            s.pop();
            if(!vis[node]){
                vis[node]=1;
                ans.push_back(node);
            }
            
            for(int i = adj[node].size()-1;i>=0;i--){
                if(!vis[adj[node][i]]){
                    
                    s.push(adj[node][i]);
                }
            }
            
        }
        
        return ans;
    }
};
