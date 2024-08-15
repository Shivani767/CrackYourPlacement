class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        unordered_map<int, int> row, col;
        for (int i = 0; i < n; i++) {
            int x = stones[i][0], y = stones[i][1];
            if (row.find(x) != row.end()) {
                unionSet(parent, row[x], i);
            }
            if (col.find(y) != col.end()) {
                unionSet(parent, col[y], i);
            }
            row[x] = i;
            col[y] = i;
        }
        
        int count = 0;
        unordered_set<int> seen;
        for (int i = 0; i < n; i++) {
            if (seen.find(find(parent, i)) == seen.end()) {
                seen.insert(find(parent, i));
                count++;
            }
        }
        
        return n - count;
    }
    
private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
    
    void unionSet(vector<int>& parent, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};
