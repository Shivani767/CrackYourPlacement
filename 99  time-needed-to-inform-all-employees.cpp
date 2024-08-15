class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> subordinates(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                subordinates[manager[i]].push_back(i);
            }
        }

        return dfs(headID, subordinates, informTime);
    }

    int dfs(int node, vector<vector<int>>& subordinates, vector<int>& informTime) {
        if (informTime[node] == 0) {
            return 0;
        }

        int maxTime = 0;
        for (int subordinate : subordinates[node]) {
            maxTime = max(maxTime, dfs(subordinate, subordinates, informTime));
        }

        return maxTime + informTime[node];
    }
};
