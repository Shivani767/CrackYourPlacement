class Solution {
private:
    // Helper function to check if the given cell is within grid bounds
    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    // DFS to mark all cells of the first island
    void DFS(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited, int m, int n) {
        if (!isSafe(i, j, m, n) || grid[i][j] == 0 || visited[i][j] == 1) return;

        visited[i][j] = 1; // Mark cell as visited (part of the first island)

        // Explore in all 4 directions
        DFS(grid, i - 1, j, visited, m, n); // Up
        DFS(grid, i + 1, j, visited, m, n); // Down
        DFS(grid, i, j + 1, visited, m, n); // Right
        DFS(grid, i, j - 1, visited, m, n); // Left
    }

    // BFS to find the shortest path (bridge) from the first island to the second
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int m, int n, vector<vector<int>>& direction) {
        queue<pair<int, int>> q;

        // Add all cells of the first island to the queue to start BFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        int level = 0; // Distance from the first island

        // Perform BFS to expand outward from the first island
        while (!q.empty()) {
            int l = q.size();

            while (l--) {
                pair<int, int> p = q.front();
                q.pop();

                int u = p.first;
                int v = p.second;

                // Explore all 4 directions from the current cell
                for (auto& dir : direction) {
                    int x = u + dir[0];
                    int y = v + dir[1];

                    // If the cell is within bounds and not visited
                    if (isSafe(x, y, m, n) && visited[x][y] == 0) {
                        visited[x][y] = 1; // Mark it as visited
                        
                        // If we find a cell of the second island, return the distance
                        if (grid[x][y] == 1) return level;

                        // Add the cell to the queue to explore it in the next level
                        q.push({x, y});
                    }
                }
            }
            level++; // Increase distance with each level of BFS
        }

        return level; // Return the shortest bridge length
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(); // Number of rows
        int m = grid[0].size(); // Number of columns

        vector<vector<int>> visited(n, vector<int>(m, 0)); // Visited array to mark visited cells

        vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Directions for exploring up, down, left, and right
        
        // Find the first island using DFS and mark it as visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    DFS(grid, i, j, visited, m, n); // Mark the first island
                    return bfs(grid, visited, m, n, direction); // Start BFS to find the shortest bridge
                }
            }
        }

        return 1; // Fallback case (though it should never reach here)
    }
};
