class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0], v = equations[i][1];
            graph[u][v] = values[i];
            graph[v][u] = 1.0 / values[i];
        }
        
        vector<double> res;
        for (auto& query : queries) {
            string u = query[0], v = query[1];
            if (graph.find(u) == graph.end() || graph.find(v) == graph.end()) {
                res.push_back(-1.0);
            } else if (u == v) {
                res.push_back(1.0);
            } else {
                unordered_set<string> visited;
                res.push_back(dfs(graph, u, v, visited));
            }
        }
        
        return res;
    }
    
private:
    double dfs(unordered_map<string, unordered_map<string, double>>& graph, string u, string v, unordered_set<string>& visited) {
        if (graph[u].find(v)!= graph[u].end()) {
            return graph[u][v];
        }
        for (auto& neighbor : graph[u]) {
            if (visited.find(neighbor.first) == visited.end()) {
                visited.insert(neighbor.first);
                double val = dfs(graph, neighbor.first, v, visited);
                if (val!= -1.0) {
                    return neighbor.second * val;
                }
            }
        }
        return -1.0;
    }
};
