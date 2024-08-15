class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n, -1);
        int extraEdges = 0;

        for (auto& conn : connections) {
            int x = find(parent, conn[0]);
            int y = find(parent, conn[1]);

            if (x == y) {
                extraEdges++;
            } else {
                parent[x] = y;
            }
        }

        int groups = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                groups++;
            }
        }

        if (extraEdges < groups - 1) {
            return -1;
        }

        return groups - 1;
    }

    int find(vector<int>& parent, int x) {
        if (parent[x] == -1) {
            return x;
        }
        return find(parent, parent[x]);
    }
};
