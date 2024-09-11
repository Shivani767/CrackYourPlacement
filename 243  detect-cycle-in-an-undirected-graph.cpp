class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfsdetect(int start, vector<int> &visited, vector<int> adj[]){
        queue<pair<int,int>> q;
        q.push({start,-1});
        visited[start]=1;
        while(!q.empty()){
            int node=q.front().first;
            int src=q.front().second;
            q.pop();
            //visited[node]=1;
            for(auto adjNode:adj[node]){
                if(visited[adjNode]!=1){
                    q.push({adjNode,node});
                    visited[adjNode]=1;
                }
                else if(adjNode!=src)
                    return true;
            }
        }
        return false;
    }
    bool dfsdetect(int node,int parent, vector<int> &visited, vector<int> adj[]){
        visited[node]=1;
        for(auto it: adj[node]){
            if(visited[it]!=1){
                if(dfsdetect(it,node,visited,adj))
                    return true;
            }
            else if(it!=parent)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]!=1){
                if(dfsdetect(i,-1,visited,adj))
                    return true;
            }
        }
        return false;
    }
};
