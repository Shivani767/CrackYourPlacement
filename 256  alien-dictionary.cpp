// User function Template for C++

class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
    vector<int> adj[k];
    
    // Build the graph by comparing adjacent words
    for (int i = 0; i < n - 1; i++) {
        string word1 = dict[i];
        string word2 = dict[i + 1];
        
        // Compare word1 and word2 character by character
        for (int j = 0; j < min(word1.length(), word2.length()); j++) {
            if (word1[j] != word2[j]) {
                // There is a directed edge from word1[j] to word2[j]
                adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                break;
            }
        }
    }
    
    // Perform topological sort using Kahn's algorithm
    vector<int> inDegree(k, 0);
    
    // Calculate in-degree of each node
    for (int i = 0; i < k; i++) {
        for (auto it : adj[i]) {
            inDegree[it]++;
        }
    }
    
    // Queue for BFS
    queue<int> q;
    // Enqueue all nodes with 0 in-degree
    for (int i = 0; i < k; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    // Resultant topological order
    string topo;
    
    // BFS (Kahn's algorithm)
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo += (char)(node + 'a');
        
        // Reduce the in-degree of adjacent nodes
        for (auto it : adj[node]) {
            inDegree[it]--;
            if (inDegree[it] == 0) {
                q.push(it);
            }
        }
    }
    
    // If topological sort contains all k characters, return the result
    if (topo.length() == k) return topo;
    
    // If not all characters are in topological order (cycle detected), return empty string
    return "";
    }
};
