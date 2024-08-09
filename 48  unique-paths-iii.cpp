class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), empty = 1, sx, sy, ex, ey;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    sx = i, sy = j;
                } else if (grid[i][j] == 2) {
                    ex = i, ey = j;
                } else if (grid[i][j] == 0) {
                    ++empty;
                }
            }
        }
        return dfs(grid, sx, sy, ex, ey, empty);
    }

private:
    int dfs(vector<vector<int>>& grid, int x, int y, int ex, int ey, int empty) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) {
            return 0;
        }
        if (grid[x][y] == 2) {
            return empty == 0 ? 1 : 0;
        }
        grid[x][y] = -1;
        int res = 0;
        res += dfs(grid, x - 1, y, ex, ey, empty - 1);
        res += dfs(grid, x + 1, y, ex, ey, empty - 1);
        res += dfs(grid, x, y - 1, ex, ey, empty - 1);
        res += dfs(grid, x, y + 1, ex, ey, empty - 1);
        grid[x][y] = 0;
        return res;
    }
};
