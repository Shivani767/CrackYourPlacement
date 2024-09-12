class DisjointSet{
public:  
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int UParent(int node){
        if(node==parent[node])
            return node;
        return parent[node] = UParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = UParent(u);
        int ulp_v = UParent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
    class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        int mx=0;
        vector<vector<int>> dirs={{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col]==0) continue;
                for(int ind=0; ind<4; ind++){
                    int newr = row + dirs[ind][0];
                    int newc = col + dirs[ind][1];
                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                        int nodeNo = row*n + col; //using formula to convert grid into 1d array for DSU
                        int adjNodeNo = newr*n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col]==1) continue;
                set<int> SetOfultimateparents;
                for(int idx=0; idx<4; idx++){
                    int newr = row + dirs[idx][0];
                    int newc = col + dirs[idx][1];
                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                        SetOfultimateparents.insert(ds.UParent(newr*n +newc));
                    }
                }
                int sizeTot=0;
                for(auto it: SetOfultimateparents){
                    sizeTot+=ds.size[it];
                }
                mx=max(mx, sizeTot+1);
            }
        }
        for(int cellNo=0; cellNo<n*n; cellNo++){
            mx = max(mx, ds.size[ds.UParent(cellNo)]);
        }
        return mx;
    }
};
