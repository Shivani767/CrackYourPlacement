class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0); // 0: unknown, 1: safe, 2: not safe
        vector<int> res;

        for (int i = 0; i < n; i++) {
            if (dfs(graph, color, i)) {
                res.push_back(i);
            }
        }

        return res;
    }

    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node) {
        if (color[node] > 0) {
            return color[node] == 1;
        }

        color[node] = 2; // mark as not safe
        for (int neighbor : graph[node]) {
            if (!dfs(graph, color, neighbor)) {
                return false;
            }
        }

        color[node] = 1; // mark as safe
        return true;
    }
};
