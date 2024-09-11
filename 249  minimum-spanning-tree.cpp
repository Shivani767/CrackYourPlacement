class Solution

{
	public:
	class DS{
	    public:
	    vector<int> size,par;
	    DS(int n){
	        size.resize(n+1,1);
	        par.resize(n+1);
	        for(int i=0;i<=n;i++){
	            par[i]=i;
	        }
	        
	    }
	    int findPar(int i){
	        if(par[i]==i){
	            return i;
	        }
	        return par[i]=findPar(par[i]);
	        
	    }
	    void UnionBySize(int u,int v){
	        int ulp_u=findPar(u);
	        int ulp_v=findPar(v);
	        if(ulp_u==ulp_v){
	            return;
	        }
	        if(size[ulp_u]>size[ulp_v]){
	            size[ulp_u]+=size[ulp_v];
	            par[ulp_u]=ulp_v;
	        }else{
	            size[ulp_v]+=size[ulp_u];
	            par[ulp_v]=ulp_u;
	        }
	    }
	    
	    
	};
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int s=0;
        vector<vector<int>> edges; 
        for(int i=0;i<V;i++){
            for(auto &it:adj[i]){
                edges.push_back({it[1],i,it[0]});
            }
        }
        sort(edges.begin(),edges.end());
        DS ds(V);
        for(auto &it:edges){
            int u=ds.findPar(it[1]);
            int v=ds.findPar(it[2]);
            if(u!=v){
                ds.UnionBySize(u,v);
                s+=it[0];
            }
        }
        return s;
    }
};
