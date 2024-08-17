class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        int res = 0, maxCount = n;
        for (int i = 0; i < n; i++) {
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, i});
            while (!pq.empty()) {
                int d = pq.top().first, u = pq.top().second;
                pq.pop();
                if (d > dist[u]) continue;
                for (auto& neighbor : graph[u]) {
                    int v = neighbor.first, w = neighbor.second;
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (dist[j] <= distanceThreshold) count++;
            }
            if (count <= maxCount) {
                maxCount = count;
                res = i;
            }
        }
        return res;
    }
};
