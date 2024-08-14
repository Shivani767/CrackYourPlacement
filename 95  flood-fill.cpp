class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image;
        dfs(image, sr, sc, oldColor, newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != oldColor) return;
        image[r][c] = newColor;
        dfs(image, r-1, c, oldColor, newColor);
        dfs(image, r+1, c, oldColor, newColor);
        dfs(image, r, c-1, oldColor, newColor);
        dfs(image, r, c+1, oldColor, newColor);
    }
};
