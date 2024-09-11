class Solution
{
	public:
       
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ans;

	 vector<int>ind(V , 0);
	 for(int i=0; i<V; i++){
	     
	     for(auto it: adj[i]){
	       
	         ind[it]++;
	     }
	 }
	queue<int> q;
	 for(int i=0; i<V; i++){
	    if(ind[i]==0)q.push(i);
	 }
	 
	  while(!q.empty()){
	      int node = q.front();
	      q.pop();
	      ans.push_back(node);
	       for(auto it : adj[node]){
	         ind[it]--;
	         if(ind[it]==0)q.push(it);
	       }
	    
	      }
	  
	 
	 return ans;
	 
	 
	}
};
