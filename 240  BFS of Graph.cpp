class Solution
   public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V);
        queue<int> q;
        vector<int> ans;
        int s=0;
        q.push(s);
        visited[s]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(int x:adj[curr]){
                if(!visited[x]){
                    visited[x]=true;
                    q.push(x);
                }
            }
        }
        return ans;
    }
};
